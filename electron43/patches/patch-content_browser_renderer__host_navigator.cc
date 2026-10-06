$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/navigator.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/navigator.cc
@@ -1450,6 +1450,7 @@ void Navigator::RecordNavigationMetrics(
             .InMilliseconds());
   }
 
+#if 0
   // If this is a same-process navigation and we have timestamps for unload
   // durations, fill those metrics out as well.
   if (params.unload_start && params.unload_end &&
@@ -1499,6 +1500,7 @@ void Navigator::RecordNavigationMetrics(
          first_before_unload_start_time)
             .InMilliseconds());
   }
+#endif
 
   builder.Record(ukm::UkmRecorder::Get());
   metrics_data_.reset();
