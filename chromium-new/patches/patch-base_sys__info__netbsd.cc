$NetBSD$

--- base/sys_info_netbsd.cc.orig	2016-11-12 07:18:17.632595486 +0000
+++ base/sys_info_netbsd.cc
@@ -0,0 +1,77 @@
+// Copyright (c) 2011 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/sys_info.h"
+
+#include <stddef.h>
+#include <stdint.h>
+#include <sys/param.h>
+#include <sys/shm.h>
+#include <sys/sysctl.h>
+
+#include "base/logging.h"
+#include "base/macros.h"
+
+namespace {
+
+int64_t AmountOfMemory(int pages_name) {
+  long pages = sysconf(pages_name);
+  long page_size = sysconf(_SC_PAGESIZE);
+  if (pages == -1 || page_size == -1) {
+    NOTREACHED();
+    return 0;
+  }
+  return static_cast<int64_t>(pages) * page_size;
+}
+
+}  // namespace
+
+namespace base {
+
+int64_t SysInfo::AmountOfPhysicalMemory() {
+  return AmountOfMemory(_SC_PHYS_PAGES);
+}
+
+// static
+int64_t SysInfo::AmountOfAvailablePhysicalMemory() {
+  int ret;
+  int mib[2];
+  int64_t memsize;
+  unsigned long size = sizeof(memsize);
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_PHYSMEM64;
+
+  ret = sysctl(mib, 2, &memsize, &size, NULL, 0);
+  if (ret == -1) {
+    return 0;
+  }
+
+  return memsize;
+}
+
+// static
+std::string SysInfo::CPUModelName() {
+  int mib[] = { CTL_HW, HW_MODEL };
+  char name[256];
+  size_t len = arraysize(name);
+  if (sysctl(mib, arraysize(mib), name, &len, NULL, 0) < 0) {
+    NOTREACHED();
+    return std::string();
+  }
+  return name;
+}
+
+int SysInfo::NumberOfProcessors() {
+  int mib[] = { CTL_HW, HW_NCPU };
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, arraysize(mib), &ncpu, &size, NULL, 0) < 0) {
+    NOTREACHED();
+    return 1;
+  }
+  return ncpu;
+}
+
+}  // namespace base
