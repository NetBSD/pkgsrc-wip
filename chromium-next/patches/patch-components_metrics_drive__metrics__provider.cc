$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/drive_metrics_provider.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ components/metrics/drive_metrics_provider.cc
@@ -113,7 +113,7 @@ void DriveMetricsProvider::FillDriveMetr
                        response.has_seek_penalty);
   RecordTriStateMetric("UMA.SeekPenaltyResult.Base",
                        response.has_seek_penalty_base);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RecordTriStateMetric("UMA.DriveIsRemovableResult", response.is_removable);
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
