$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/metrics/power/process_metrics_recorder_util.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/metrics/power/process_metrics_recorder_util.cc
@@ -65,7 +65,7 @@ void RecordProcessHistograms(const char*
                              const ProcessMonitor::Metrics& metrics) {
   RecordAverageCPUUsage(histogram_suffix, metrics.cpu_usage);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::StrCat({"PerformanceMonitor.IdleWakeups2.", histogram_suffix}),
       metrics.idle_wakeups);
