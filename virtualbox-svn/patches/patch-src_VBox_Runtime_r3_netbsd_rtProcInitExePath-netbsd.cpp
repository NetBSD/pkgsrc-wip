$NetBSD$

--- src/VBox/Runtime/r3/netbsd/rtProcInitExePath-netbsd.cpp.orig	2016-07-07 07:08:47.060017160 +0000
+++ src/VBox/Runtime/r3/netbsd/rtProcInitExePath-netbsd.cpp
@@ -0,0 +1,72 @@
+/*  rtProcInitExePath-netbsd.cpp $ */
+/** @file
+ * IPRT - rtProcInitName, NetBSD.
+ */
+
+/*
+ * Copyright (C) 2006-2015 Oracle Corporation
+ *
+ * This file is part of VirtualBox Open Source Edition (OSE), as
+ * available from http://www.virtualbox.org. This file is free software;
+ * you can redistribute it and/or modify it under the terms of the GNU
+ * General Public License (GPL) as published by the Free Software
+ * Foundation, in version 2 as it comes in the "COPYING" file of the
+ * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+ * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+ *
+ * The contents of this file may alternatively be used under the terms
+ * of the Common Development and Distribution License Version 1.0
+ * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
+ * VirtualBox OSE distribution, in which case the provisions of the
+ * CDDL are applicable instead of those of the GPL.
+ *
+ * You may elect to license modified versions of this file under the
+ * terms and conditions of either the GPL or the CDDL or both.
+ */
+
+
+/*********************************************************************************************************************************
+*   Header Files                                                                                                                 *
+*********************************************************************************************************************************/
+#define LOG_GROUP RTLOGGROUP_PROCESS
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+#include <errno.h>
+#include <dlfcn.h>
+#include <link.h>
+
+#include <iprt/string.h>
+#include <iprt/assert.h>
+#include <iprt/err.h>
+#include <iprt/path.h>
+#include "internal/process.h"
+#include "internal/path.h"
+
+
+DECLHIDDEN(int) rtProcInitExePath(char *pszPath, size_t cchPath)
+{
+    int aiName[4];
+    aiName[0] = CTL_KERN;
+    aiName[1] = KERN_PROC_ARGS;
+    aiName[2] = -1;                     /* Shorthand for the current process. */
+    aiName[3] = KERN_PROC_PATHNAME;
+
+    size_t cchExePath = cchPath;
+    if (sysctl(aiName, RT_ELEMENTS(aiName), pszPath, &cchExePath, NULL, 0) == 0)
+    {
+        const char *pszTmp;
+        int rc = rtPathFromNative(&pszTmp, pszPath, NULL);
+        AssertMsgRCReturn(rc, ("rc=%Rrc pszPath=\"%s\"\nhex: %.*Rhxs\n", rc, pszPath, cchExePath, pszPath), rc);
+        if (pszTmp != pszPath)
+        {
+            rc = RTStrCopy(pszPath, cchPath, pszTmp);
+            rtPathFreeIprt(pszTmp, pszPath);
+        }
+        return rc;
+    }
+
+    int rc = RTErrConvertFromErrno(errno);
+    AssertMsgFailed(("rc=%Rrc errno=%d cchExePath=%d\n", rc, errno, cchExePath));
+    return rc;
+}
