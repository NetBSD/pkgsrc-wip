$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/process/process_metrics.h.orig	2024-10-18 12:33:59.794258600 +0000
+++ base/process/process_metrics.h
@@ -38,7 +38,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 #include <string>
 #include <utility>
 #include <vector>
@@ -48,7 +48,7 @@
 
 namespace base {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -116,7 +116,7 @@ class BASE_EXPORT ProcessMetrics {
   // convenience wrapper for CreateProcessMetrics().
   static std::unique_ptr<ProcessMetrics> CreateCurrentProcessMetrics();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Resident Set Size is a Linux/Android specific memory concept. Do not
   // attempt to extend this to other platforms.
   BASE_EXPORT size_t GetResidentSetSize() const;
@@ -150,7 +150,7 @@ class BASE_EXPORT ProcessMetrics {
   base::expected<TimeDelta, ProcessCPUUsageError> GetCumulativeCPUUsage();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   // Emits the cumulative CPU usage for all currently active threads since they
   // were started into the output parameter (replacing its current contents).
   // Threads that have already terminated will not be reported. Thus, the sum of
@@ -195,7 +195,7 @@ class BASE_EXPORT ProcessMetrics {
   int GetOpenFdSoftLimit() const;
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
@@ -216,7 +216,7 @@ class BASE_EXPORT ProcessMetrics {
 #endif  // !BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if BUILDFLAG(IS_APPLE)
@@ -238,12 +238,10 @@ class BASE_EXPORT ProcessMetrics {
   // Used to store the previous times and CPU usage counts so we can
   // compute the CPU usage between calls.
   TimeTicks last_cpu_time_;
-#if !BUILDFLAG(IS_FREEBSD) || !BUILDFLAG(IS_POSIX)
   TimeDelta last_cumulative_cpu_;
-#endif
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -284,7 +282,7 @@ BASE_EXPORT void IncreaseFdLimitTo(unsig
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||      \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_AIX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -319,7 +317,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -334,7 +332,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
@@ -371,7 +369,7 @@ BASE_EXPORT bool GetSystemMemoryInfo(Sys
         // BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
@@ -566,7 +564,7 @@ class BASE_EXPORT SystemMetrics {
   FRIEND_TEST_ALL_PREFIXES(SystemMetricsTest, SystemMetrics);
 
   size_t committed_memory_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   SystemMemoryInfoKB memory_info_;
   VmStatInfo vmstat_info_;
   SystemDiskInfo disk_info_;
