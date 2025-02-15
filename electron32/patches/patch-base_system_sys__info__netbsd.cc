$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/system/sys_info_netbsd.cc.orig	2025-02-15 11:29:58.206386924 +0000
+++ base/system/sys_info_netbsd.cc
@@ -0,0 +1,91 @@
+// Copyright 2011 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/system/sys_info.h"
+
+#include <stddef.h>
+#include <stdint.h>
+#include <sys/param.h>
+#include <sys/shm.h>
+#include <sys/sysctl.h>
+
+#include "base/notreached.h"
+#include "base/posix/sysctl.h"
+#include "base/strings/string_util.h"
+
+namespace {
+
+uint64_t AmountOfMemory(int pages_name) {
+  long pages = sysconf(pages_name);
+  long page_size = sysconf(_SC_PAGESIZE);
+  if (pages < 0 || page_size < 0)
+    return 0;
+  return static_cast<uint64_t>(pages) * static_cast<uint64_t>(page_size);
+}
+
+}  // namespace
+
+namespace base {
+
+// static
+int SysInfo::NumberOfProcessors() {
+  int mib[] = {CTL_HW, HW_NCPU};
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
+    NOTREACHED_IN_MIGRATION();
+    return 1;
+  }
+  return ncpu;
+}
+
+// static
+uint64_t SysInfo::AmountOfPhysicalMemoryImpl() {
+  return AmountOfMemory(_SC_PHYS_PAGES);
+}
+
+// static
+uint64_t SysInfo::AmountOfAvailablePhysicalMemoryImpl() {
+  return AmountOfMemory(_SC_PHYS_PAGES);
+}
+
+// static
+uint64_t SysInfo::MaxSharedMemorySize() {
+  int mib[] = {CTL_KERN, KERN_SYSVIPC, KERN_SYSVIPC_SHMMAX};
+  size_t limit;
+  size_t size = sizeof(limit);
+  // pledge(2)
+  if (sysctl(mib, std::size(mib), &limit, &size, NULL, 0) < 0) {
+    NOTREACHED_IN_MIGRATION();
+    return 0;
+  }
+  return static_cast<uint64_t>(limit);
+}
+
+// static
+std::string SysInfo::CPUModelName() {
+  int mib[] = { CTL_HW, HW_MODEL };
+  char name[256];
+  size_t size = std::size(name);
+
+  if (sysctl(mib, std::size(mib), &name, &size, NULL, 0) == 0) {
+    return name;
+  }
+
+  return std::string();
+}
+
+// static
+SysInfo::HardwareInfo SysInfo::GetHardwareInfoSync() {
+  HardwareInfo info;
+  // Set the manufacturer to "NetBSD" and the model to
+  // an empty string.
+  info.manufacturer = "NetBSD";
+  info.model = HardwareModelName();
+  DCHECK(IsStringUTF8(info.manufacturer));
+  DCHECK(IsStringUTF8(info.model));
+  return info;
+}
+
+}  // namespace base
