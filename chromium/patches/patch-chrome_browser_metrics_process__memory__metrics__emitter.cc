$NetBSD$

--- chrome/browser/metrics/process_memory_metrics_emitter.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/metrics/process_memory_metrics_emitter.cc
@@ -492,7 +492,7 @@ void EmitProcessUmaAndUkm(const GlobalMe
 
   builder->SetPrivateMemoryFootprint(pmd.os_dump().private_footprint_kb / kKiB);
   builder->SetSharedMemoryFootprint(pmd.os_dump().shared_footprint_kb / kKiB);
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   builder->SetPrivateSwapFootprint(pmd.os_dump().private_footprint_swap_kb /
                                    kKiB);
 #endif
@@ -515,7 +515,7 @@ void EmitProcessUmaAndUkm(const GlobalMe
   MEMORY_METRICS_HISTOGRAM_MB(std::string(kMemoryHistogramPrefix) +
                                   process_name + ".SharedMemoryFootprint",
                               pmd.os_dump().shared_footprint_kb / kKiB);
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   MEMORY_METRICS_HISTOGRAM_MB(std::string(kMemoryHistogramPrefix) +
                                   process_name + ".PrivateSwapFootprint",
                               pmd.os_dump().private_footprint_swap_kb / kKiB);
