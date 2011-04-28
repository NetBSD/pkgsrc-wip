$NetBSD: patch-base_sys__info__netbsd.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/sys_info_netbsd.cc.orig	2011-04-26 05:17:12.000000000 +0000
+++ base/sys_info_netbsd.cc
@@ -0,0 +1,25 @@
+// Copyright (c) 2009 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/sys_info.h"
+
+#include <sys/param.h>
+#include <sys/sysctl.h>
+
+#include "base/logging.h"
+
+namespace base {
+
+int SysInfo::NumberOfProcessors() {
+  int mib[] = { CTL_HW, HW_NCPU };
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, 2, &ncpu, &size, NULL, 0) == -1) {
+    NOTREACHED();
+    return 1;
+  }
+  return ncpu;
+}
+
+}  // namespace base
