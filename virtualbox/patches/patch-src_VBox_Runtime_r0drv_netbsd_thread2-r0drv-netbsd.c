$NetBSD$

--- src/VBox/Runtime/r0drv/netbsd/thread2-r0drv-netbsd.c.orig	2016-07-07 07:08:47.013842911 +0000
+++ src/VBox/Runtime/r0drv/netbsd/thread2-r0drv-netbsd.c
@@ -0,0 +1,134 @@
+/*  thread2-r0drv-netbsd.c $ */
+/** @file
+ * IPRT - Threads (Part 2), Ring-0 Driver, NetBSD.
+ */
+
+/*
+ * Copyright (c) 2007 knut st. osmundsen <bird-src-spam@anduin.net>
+ *
+ * Permission is hereby granted, free of charge, to any person
+ * obtaining a copy of this software and associated documentation
+ * files (the "Software"), to deal in the Software without
+ * restriction, including without limitation the rights to use,
+ * copy, modify, merge, publish, distribute, sublicense, and/or sell
+ * copies of the Software, and to permit persons to whom the
+ * Software is furnished to do so, subject to the following
+ * conditions:
+ *
+ * The above copyright notice and this permission notice shall be
+ * included in all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
+ * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
+ * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
+ * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
+ * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
+ * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
+ * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
+ * OTHER DEALINGS IN THE SOFTWARE.
+ */
+
+
+/*********************************************************************************************************************************
+*   Header Files                                                                                                                 *
+*********************************************************************************************************************************/
+#include "the-netbsd-kernel.h"
+
+#include <iprt/thread.h>
+#include <iprt/err.h>
+#include <iprt/assert.h>
+
+#include "internal/thread.h"
+
+
+DECLHIDDEN(int) rtThreadNativeInit(void)
+{
+    return VINF_SUCCESS;
+}
+
+
+RTDECL(RTTHREAD) RTThreadSelf(void)
+{
+    return rtThreadGetByNative(RTThreadNativeSelf());
+}
+
+
+DECLHIDDEN(int) rtThreadNativeSetPriority(PRTTHREADINT pThread, RTTHREADTYPE enmType)
+{
+    int iPriority;
+
+    switch (enmType)
+    {
+        case RTTHREADTYPE_INFREQUENT_POLLER:    iPriority = PZERO + 8;      break;
+        case RTTHREADTYPE_EMULATION:            iPriority = PZERO + 4;      break;
+        case RTTHREADTYPE_DEFAULT:              iPriority = PZERO;          break;
+        case RTTHREADTYPE_MSG_PUMP:             iPriority = PZERO - 4;      break;
+        case RTTHREADTYPE_IO:                   iPriority = PRIBIO;         break;
+        case RTTHREADTYPE_TIMER:                iPriority = PRI_MIN_KERN;   break;
+        default:
+            AssertMsgFailed(("enmType=%d\n", enmType));
+            return VERR_INVALID_PARAMETER;
+    }
+
+    thread_lock(curthread);
+    sched_prio(curthread, iPriority);
+    thread_unlock(curthread);
+
+    return VINF_SUCCESS;
+}
+
+
+DECLHIDDEN(int) rtThreadNativeAdopt(PRTTHREADINT pThread)
+{
+    NOREF(pThread);
+    /* There is nothing special that needs doing here, but the
+       user really better know what he's cooking. */
+    return VINF_SUCCESS;
+}
+
+
+DECLHIDDEN(void) rtThreadNativeWaitKludge(PRTTHREADINT pThread)
+{
+    /** @todo fix RTThreadWait/RTR0Term race on netbsd. */
+    RTThreadSleep(1);
+}
+
+
+DECLHIDDEN(void) rtThreadNativeDestroy(PRTTHREADINT pThread)
+{
+    NOREF(pThread);
+}
+
+
+/**
+ * Native thread main function.
+ *
+ * @param   pvThreadInt     The thread structure.
+ */
+static void rtThreadNativeMain(void *pvThreadInt)
+{
+    const struct thread *Self = curthread;
+    PRTTHREADINT pThreadInt = (PRTTHREADINT)pvThreadInt;
+    int rc;
+
+    rc = rtThreadMain(pThreadInt, (RTNATIVETHREAD)Self, &pThreadInt->szName[0]);
+
+    kproc_exit(rc);
+}
+
+
+DECLHIDDEN(int) rtThreadNativeCreate(PRTTHREADINT pThreadInt, PRTNATIVETHREAD pNativeThread)
+{
+    int rc;
+    struct proc *pProc;
+
+    rc = kproc_create(rtThreadNativeMain, pThreadInt, &pProc, RFHIGHPID, 0, "%s", pThreadInt->szName);
+    if (!rc)
+    {
+        *pNativeThread = (RTNATIVETHREAD)FIRST_THREAD_IN_PROC(pProc);
+        rc = VINF_SUCCESS;
+    }
+    else
+        rc = RTErrConvertFromErrno(rc);
+    return rc;
+}
