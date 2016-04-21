$NetBSD$

--- src/pal/src/thread/thread.cpp.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/pal/src/thread/thread.cpp
@@ -33,6 +33,13 @@ Abstract:
 #include "pal/environ.h"
 #include "pal/init.h"
 
+#if defined(__NetBSD__) && !defined(HAVE_PTHREAD_GETCPUCLOCKID)
+#include <sys/cdefs.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/kvm.h>
+#endif
+
 #include <signal.h>
 #include <pthread.h>
 #if HAVE_PTHREAD_NP_H
@@ -1399,6 +1406,89 @@ CorUnix::GetThreadTimesInternal(
 
     goto GetThreadTimesInternalExit;
 
+#elif defined(__NetBSD__) && !defined(HAVE_PTHREAD_GETCPUCLOCKID) /* Currently unimplemented */
+
+    PAL_ERROR palError;
+    CPalThread *pThread;
+    CPalThread *pTargetThread;
+    IPalObject *pobjThread = NULL;
+    kvm_t *kd;
+    int cnt, nlwps;
+    struct kinfo_lwp *klwp;
+    int i;
+    bool found = false;
+
+    pThread = InternalGetCurrentThread();
+
+    palError = InternalGetThreadDataFromHandle(
+        pThread,
+        hThread,
+        0, // THREAD_GET_CONTEXT
+        &pTargetThread,
+        &pobjThread
+        );
+    if (palError != NO_ERROR)
+    {
+        ASSERT("Unable to get thread data from handle %p"
+              "thread\n", hThread);
+        SetLastError(ERROR_INTERNAL_ERROR);
+        goto SetTimesToZero;
+    }
+
+    kd = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, "kvm_open");
+    if (kd == NULL)
+    {
+        ASSERT("kvm_open(3) error");
+        SetLastError(ERROR_INTERNAL_ERROR);
+        goto SetTimesToZero;
+    }
+
+    pTargetThread->Lock(pThread);
+
+    klwp = kvm_getlwps(kd, getpid(), 0, sizeof(struct kinfo_lwp), &nlwps);
+    if (klwp == NULL || nlwps < 1)
+    {
+        kvm_close(kd);
+        ASSERT("Unable to get clock from %p thread\n", hThread);
+        SetLastError(ERROR_INTERNAL_ERROR);
+        pTargetThread->Unlock(pThread);
+        goto SetTimesToZero;
+    }
+
+    for (i = 0; i < nlwps; i++)
+    {
+        if (klwp[i].l_lid == lwpid)
+        {
+            found = true;
+            break;
+        }
+    }
+
+    if (!found)
+    {
+        kvm_close(kd);
+        ASSERT("Unable to get clock from %p thread\n", hThread);
+        SetLastError(ERROR_INTERNAL_ERROR);
+        pTargetThread->Unlock(pThread);
+        goto SetTimesToZero;
+    }
+
+    pTargetThread->Unlock(pThread);
+
+    kvm_close(kd);
+
+    calcTime = (__int64) klwp[i].l_rtime_sec * SECS_TO_NS;
+    calcTime += (__int64) klwp[i].l_rtime_usec / 1000;
+    lpUserTime->dwLowDateTime = (DWORD)calcTime;
+    lpUserTime->dwHighDateTime = (DWORD)(calcTime >> 32);
+
+    /* NetBSD as of (7.0) doesn't differentiate used time in user/kernel for lwp */
+    lpKernelTime->dwLowDateTime = 0;
+    lpKernelTime->dwHighDateTime = 0;
+
+    retval = TRUE;
+    goto GetThreadTimesInternalExit;
+
 #else //HAVE_MACH_THREADS
 
     PAL_ERROR palError;
