$NetBSD$

--- src/3rdparty/chromium/components/metrics/system_memory_stats_recorder_linux.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/metrics/system_memory_stats_recorder_linux.cc
@@ -30,6 +30,7 @@ namespace metrics {
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_BSD)
   base::SystemMemoryInfoKB memory;
   if (!base::GetSystemMemoryInfo(&memory))
     return;
@@ -81,6 +82,7 @@ void RecordMemoryStats(RecordMemoryStats
       break;
     }
   }
+#endif
 }
 
 }  // namespace metrics
