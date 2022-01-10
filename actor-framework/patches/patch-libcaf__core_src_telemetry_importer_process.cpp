$NetBSD$

* Add Solaris support
* Add NetBSD support

--- libcaf_core/src/telemetry/importer/process.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/telemetry/importer/process.cpp
@@ -10,7 +10,7 @@
 
 // -- detect supported platforms -----------------------------------------------
 
-#if defined(CAF_MACOS) || defined(CAF_LINUX)
+#if defined(CAF_MACOS) || defined(CAF_LINUX) || defined(CAF_SOLARIS) || defined(CAF_NETBSD)
 #  define CAF_HAS_PROCESS_METRICS
 #endif
 
@@ -212,6 +212,90 @@ sys_stats read_sys_stats() {
 
 #endif // CAF_LINUX
 
+#if defined(CAF_SOLARIS)
+
+#  include <procfs.h>
+#  include <stdio.h>
+#  include <unistd.h>
+
+namespace {
+
+sys_stats read_sys_stats() {
+  sys_stats result{0, 0, 0};
+  char procfs_path[32];
+
+  snprintf(procfs_path, sizeof(procfs_path), "/proc/%d/psinfo", getpid());
+
+  if (auto f = fopen(procfs_path, "r")) {
+    psinfo_t ppsi;
+
+    auto rd = fread(&ppsi, sizeof(ppsi), 1, f);
+    fclose(f);
+    if (rd != 1) {
+       CAF_LOG_ERROR("failed to read content of" << procfs_path);
+       return result;
+    }
+
+    result.rss = static_cast<int64_t>(ppsi.pr_rssize) * 1024;
+    result.vms = static_cast<int64_t>(ppsi.pr_size) * 1024;
+    result.cpu_time = ppsi.pr_time.tv_sec;
+    result.cpu_time += static_cast<double>(ppsi.pr_time.tv_nsec) / 1000000000;
+  }
+  else {
+    CAF_LOG_ERROR("failed to open file" << procfs_path);
+  }
+
+  return result;
+}
+
+} // namespace 
+
+#endif // CAF_SOLARIS
+
+#if defined(CAF_NETBSD)
+
+#include <sys/sysctl.h>
+#include <unistd.h>
+
+namespace {
+
+sys_stats read_sys_stats() {
+  sys_stats result{0, 0, 0};
+  int mib[6];
+  struct kinfo_proc2 kip2;
+  size_t kip2_size = sizeof(kip2);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = getpid();
+  mib[4] = kip2_size;
+  mib[5] = 1;
+
+  long page_size = sysconf(_SC_PAGE_SIZE);
+  if (page_size == -1) {
+    CAF_LOG_ERROR("getting _SC_PAGE_SIZE from sysconf failed in read_sys_stats");
+    return result;
+  }
+
+
+  if (sysctl(mib, 6, &kip2, &kip2_size, NULL, (size_t)0)) {
+    CAF_LOG_ERROR("sysctl failed in read_sys_stats");
+    return result;
+  }
+
+  result.rss = static_cast<int64_t>(kip2.p_vm_rssize) * page_size;
+  result.vms = static_cast<int64_t>(kip2.p_vm_vsize) * page_size;
+  result.cpu_time = kip2.p_rtime_sec;
+  result.cpu_time += static_cast<double>(kip2.p_rtime_usec) / 1000000;
+
+  return result;
+}
+
+} // namepace
+
+#endif // CAF_NETBSD
+
 namespace caf::telemetry::importer {
 
 process::process(metric_registry& reg) {
