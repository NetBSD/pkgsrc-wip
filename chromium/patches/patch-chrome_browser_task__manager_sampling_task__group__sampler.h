$NetBSD$

--- chrome/browser/task_manager/sampling/task_group_sampler.h.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_group_sampler.h
@@ -32,7 +32,7 @@ class TaskGroupSampler : public base::Re
   using OnCpuRefreshCallback = base::Callback<void(double)>;
   using OnSwappedMemRefreshCallback = base::Callback<void(int64_t)>;
   using OnIdleWakeupsCallback = base::Callback<void(int)>;
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   using OnOpenFdCountCallback = base::Callback<void(int)>;
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
   using OnProcessPriorityCallback = base::Callback<void(bool)>;
@@ -43,7 +43,7 @@ class TaskGroupSampler : public base::Re
       const OnCpuRefreshCallback& on_cpu_refresh,
       const OnSwappedMemRefreshCallback& on_memory_refresh,
       const OnIdleWakeupsCallback& on_idle_wakeups,
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       const OnOpenFdCountCallback& on_open_fd_count,
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
       const OnProcessPriorityCallback& on_process_priority);
@@ -60,7 +60,7 @@ class TaskGroupSampler : public base::Re
   double RefreshCpuUsage();
   int64_t RefreshSwappedMem();
   int RefreshIdleWakeupsPerSecond();
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   int RefreshOpenFdCount();
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
   bool RefreshProcessPriority();
@@ -84,7 +84,7 @@ class TaskGroupSampler : public base::Re
   const OnCpuRefreshCallback on_cpu_refresh_callback_;
   const OnSwappedMemRefreshCallback on_swapped_mem_refresh_callback_;
   const OnIdleWakeupsCallback on_idle_wakeups_callback_;
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   const OnOpenFdCountCallback on_open_fd_count_callback_;
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX)
   const OnProcessPriorityCallback on_process_priority_callback_;
