$NetBSD$

* Add Solaris support

--- libcaf_core/src/telemetry/importer/process.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/telemetry/importer/process.cpp
@@ -10,7 +10,7 @@
 
 // -- detect supported platforms -----------------------------------------------
 
-#if defined(CAF_MACOS) || defined(CAF_LINUX)
+#if defined(CAF_MACOS) || defined(CAF_LINUX) || defined(CAF_SOLARIS)
 #  define CAF_HAS_PROCESS_METRICS
 #endif
 
@@ -212,6 +212,48 @@ sys_stats read_sys_stats() {
 
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
+       CAF_LOG_ERROR("failed to read content of " + procfs_path);
+       return result;
+    }
+
+    result.rss = static_cast<int64_t>(ppsi.pr_rssize) * 1024;
+    result.vms = static_cast<int64_t>(ppsi.pr_size) * 1024;
+    result.cpu_time = ppsi.pr_time.tv_sec;
+    if (ppsi.pr_time.tv_nsec > 500000000) {
+      result.cpu_time += 1;
+    }
+  }
+  else {
+    CAF_LOG_ERROR("failed to open file " + procfs_path);
+  }
+
+  return result;
+}
+
+} // namespace 
+
+#endif // CAF_SOLARIS
+
 namespace caf::telemetry::importer {
 
 process::process(metric_registry& reg) {
