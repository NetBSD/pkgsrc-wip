$NetBSD$

--- components/metrics/system_memory_stats_recorder_linux.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/metrics/system_memory_stats_recorder_linux.cc
@@ -30,6 +30,7 @@ namespace metrics {
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_FREEBSD)
   base::SystemMemoryInfoKB memory;
   if (!base::GetSystemMemoryInfo(&memory))
     return;
@@ -93,6 +94,7 @@ void RecordMemoryStats(RecordMemoryStats
       break;
     }
   }
+#endif // !defined(OS_FREEBSD)
 }
 
 }  // namespace metrics
