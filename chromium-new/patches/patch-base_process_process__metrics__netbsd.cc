$NetBSD$

--- base/process/process_metrics_netbsd.cc.orig	2016-07-17 08:36:13.090234675 +0000
+++ base/process/process_metrics_netbsd.cc
@@ -0,0 +1,201 @@
+// Copyright (c) 2013 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process/process_metrics.h"
+
+#include <stddef.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <unistd.h>
+
+#include "base/macros.h"
+#include "base/sys_info.h"
+
+#include <unistd.h> /* getpagesize() */
+#include <fcntl.h>  /* O_RDONLY */
+
+#include <uvm/uvm_extern.h> /* struct vmtotal */
+
+namespace base {
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process)
+    : process_(process),
+      last_system_time_(0),
+      last_cpu_(0) {
+  processor_count_ = base::SysInfo::NumberOfProcessors();
+}
+
+// static
+ProcessMetrics* ProcessMetrics::CreateProcessMetrics(ProcessHandle process) {
+  return new ProcessMetrics(process);
+}
+
+size_t ProcessMetrics::GetPagefileUsage() const {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+  int ret;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+  mib[4] = info_size;
+  mib[5] = 1;
+
+  ret = sysctl(mib, 6, &info, &info_size, NULL, 0);
+  if (ret == -1) {
+    return 0;
+  }
+
+  if (info_size == 0) {
+    return 0;
+  }
+
+  return (info.p_vm_tsize + info.p_vm_dsize + info.p_vm_ssize);
+}
+
+size_t ProcessMetrics::GetPeakPagefileUsage() const {
+  printf("%s\n", __PRETTY_FUNCTION__);
+  return 0;
+}
+
+size_t ProcessMetrics::GetWorkingSetSize() const {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+  int ret;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+  mib[4] = info_size;
+  mib[5] = 1;
+
+  ret = sysctl(mib, 6, &info, &info_size, NULL, 0);
+  if (ret == -1) {
+    return 0;
+  }
+
+  if (info_size == 0) {
+    return 0;
+  }
+
+  return info.p_vm_rssize * getpagesize();
+}
+
+size_t ProcessMetrics::GetPeakWorkingSetSize() const {
+  return 0;
+}
+
+bool ProcessMetrics::GetMemoryBytes(size_t* private_bytes,
+                                    size_t* shared_bytes) {
+  WorkingSetKBytes ws_usage;
+  if (!GetWorkingSetKBytes(&ws_usage))
+    return false;
+
+  if (private_bytes)
+    *private_bytes = ws_usage.priv << 10;
+
+  if (shared_bytes)
+    *shared_bytes = ws_usage.shared * 1024;
+
+  return true;
+}
+
+bool ProcessMetrics::GetWorkingSetKBytes(WorkingSetKBytes* ws_usage) const {
+// TODO(bapt) be sure we can't be precise
+  size_t priv = GetWorkingSetSize();
+  if (!priv)
+    return false;
+  ws_usage->priv = priv / 1024;
+  ws_usage->shareable = 0;
+  ws_usage->shared = 0;
+
+  return true;
+}
+
+double ProcessMetrics::GetCPUUsage() {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+  int ret;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+  mib[4] = info_size;
+  mib[5] = 1;
+
+  ret = sysctl(mib, 6, &info, &info_size, NULL, 0);
+  if (ret == -1) {
+    return 0;
+  }
+
+  if (info_size == 0) {
+    return 0;
+  }
+
+  return (info.p_pctcpu / FSCALE) * 100.0;
+}
+
+bool ProcessMetrics::GetIOCounters(IoCounters* io_counters) const {
+/* ryoon: should be written */
+  return false;
+}
+
+size_t GetSystemCommitCharge() {
+  int mib[2], pagesize;
+  struct vmtotal vmtotal;
+  unsigned long mem_total, mem_free, mem_inactive;
+  size_t len = sizeof(vmtotal);
+  int ret;
+
+  printf("%s\n", __PRETTY_FUNCTION__);
+
+  mib[0] = CTL_VM;
+  mib[1] = VM_METER;
+
+  ret = sysctl(mib, 2, &vmtotal, &len, NULL, 0);
+  if (ret == -1) {
+    return 0;
+  }
+
+  mem_total = vmtotal.t_vm;
+  mem_free = vmtotal.t_free;
+  mem_inactive = vmtotal.t_vm - vmtotal.t_avm;
+
+  pagesize = getpagesize();
+
+  return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+int GetNumberOfThreads(ProcessHandle process) {
+  int ret;
+  int mib[6];
+  struct kinfo_proc2 info;
+  size_t info_size = sizeof(info);
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
+    return 0;
+  }
+
+  if (info_size == 0) {
+    return 0;
+  }
+
+  return info.p_nlwps;
+}
+
+}  // namespace base
