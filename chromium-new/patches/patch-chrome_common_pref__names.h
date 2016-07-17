$NetBSD$

--- chrome/common/pref_names.h.orig	2016-06-24 01:02:15.000000000 +0000
+++ chrome/common/pref_names.h
@@ -307,7 +307,7 @@ extern const char kRecordHistory[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
 extern const char kClearBrowsingDataHistoryNoticeShownTimes[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -477,7 +477,7 @@ extern const char kAppWindowPlacement[];
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 
