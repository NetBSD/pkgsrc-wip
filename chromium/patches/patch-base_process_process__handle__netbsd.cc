$NetBSD$

--- base/process/process_handle_netbsd.cc.orig	2016-11-16 08:03:06.205887318 +0000
+++ base/process/process_handle_netbsd.cc
@@ -0,0 +1,66 @@
+// Copyright (c) 2011 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/macros.h"
+#include "base/process/process_handle.h"
+
+#include <stddef.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <unistd.h>
+
+namespace base {
+
+ProcessId GetParentProcessId(ProcessHandle process) {
+  struct kinfo_proc2 info;
+  size_t info_size = sizeof(struct kinfo_proc2);
+  int mib[6];
+  int ret;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process;
+  mib[4] = info_size;
+  mib[5] = 1;
+
+  ret = sysctl(mib, 6, &info, &info_size, NULL, 0);
+  if (ret == -1) {
+    return -1;
+  }
+  if (info_size == 0) {
+    return -1;
+  }
+
+  return info.p_ppid;
+}
+
+FilePath GetProcessExecutablePath(ProcessHandle process) {
+  size_t size = sizeof(struct kinfo_proc2);
+  int mib[4];
+  int ret;
+  char pathname[MAXPATHLEN];
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC_ARGS;
+  mib[2] = process;
+  mib[3] = KERN_PROC_PATHNAME;
+
+  ret = sysctl(mib, 4, NULL, &size, NULL, 0);
+  if (ret == -1) {
+    return FilePath();
+  }
+
+  ret = sysctl(mib, 4, pathname, &size, NULL, 0);
+  if (ret == -1) {
+    return FilePath();
+  }
+  if (size == 0 || strlen(pathname) == 0) {
+    return FilePath();
+  }
+
+  return FilePath(pathname);
+}
+
+}  // namespace base
