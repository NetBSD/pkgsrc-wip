$NetBSD$

--- src/VBox/Runtime/r3/netbsd/systemmem-netbsd.cpp.orig	2016-07-07 07:08:47.069137512 +0000
+++ src/VBox/Runtime/r3/netbsd/systemmem-netbsd.cpp
@@ -0,0 +1,74 @@
+/*  systemmem-netbsd.cpp $ */
+/** @file
+ * IPRT - RTSystemQueryTotalRam, NetBSD ring-3.
+ */
+
+/*
+ * Copyright (C) 2012-2015 Oracle Corporation
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
+#include <iprt/system.h>
+#include "internal/iprt.h"
+
+#include <iprt/err.h>
+#include <iprt/assert.h>
+#include <iprt/string.h>
+
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <errno.h>
+
+
+RTDECL(int) RTSystemQueryTotalRam(uint64_t *pcb)
+{
+    int rc = VINF_SUCCESS;
+    u_long cbMemPhys = 0;
+    size_t cbParameter = sizeof(cbMemPhys);
+
+    AssertPtrReturn(pcb, VERR_INVALID_POINTER);
+
+    if (!sysctlbyname("hw.physmem64", &cbMemPhys, &cbParameter, NULL, 0))
+    {
+        *pcb = cbMemPhys;
+        return VINF_SUCCESS;
+    }
+    return RTErrConvertFromErrno(errno);
+}
+
+
+RTDECL(int) RTSystemQueryAvailableRam(uint64_t *pcb)
+{
+    int rc = VINF_SUCCESS;
+    u_long cbMemPhys = 0;
+    size_t cbParameter = sizeof(cbMemPhys);
+
+    AssertPtrReturn(pcb, VERR_INVALID_POINTER);
+
+    if (!sysctlbyname("hw.usermem64", &cbMemPhys, &cbParameter, NULL, 0))
+    {
+        *pcb = cbMemPhys;
+        return VINF_SUCCESS;
+    }
+    return RTErrConvertFromErrno(errno);
+}
