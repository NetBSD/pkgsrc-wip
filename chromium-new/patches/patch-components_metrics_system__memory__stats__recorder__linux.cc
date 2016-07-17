$NetBSD$

--- components/metrics/system_memory_stats_recorder_linux.cc.orig	2016-06-24 01:02:18.000000000 +0000
+++ components/metrics/system_memory_stats_recorder_linux.cc
@@ -30,6 +30,7 @@ namespace metrics {
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   base::SystemMemoryInfoKB memory;
   if (!base::GetSystemMemoryInfo(&memory))
     return;
@@ -93,6 +94,7 @@ void RecordMemoryStats(RecordMemoryStats
       break;
     }
   }
+#endif // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 }
 
 }  // namespace metrics
