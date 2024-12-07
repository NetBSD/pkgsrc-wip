$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2024-12-03 23:30:25.422253600 +0000
+++ services/device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -136,7 +136,11 @@ class TimeZoneMonitorLinuxImpl
     // false positives are harmless, assuming the false positive rate is
     // reasonable.
     const char* const kFilesToWatch[] = {
+#if BUILDFLAG(IS_BSD)
+        "@PKG_SYSCONFBASE@/localtime",
+#else
         "/etc/localtime", "/etc/timezone", "/etc/TZ",
+#endif
     };
     for (size_t index = 0; index < std::size(kFilesToWatch); ++index) {
       file_path_watchers_.push_back(std::make_unique<base::FilePathWatcher>());
