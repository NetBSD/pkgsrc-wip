$NetBSD$

--- chrome/common/pref_names.h.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/common/pref_names.h
@@ -315,7 +315,7 @@ extern const char kForceSessionSync[];
 extern const char kAllowedDomainsForApps[];
 extern const char kLastClearBrowsingDataTime[];
 extern const char kClearBrowsingDataHistoryNoticeShownTimes[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -347,7 +347,7 @@ extern const char kDefaultBrowserSetting
 #if defined(OS_MACOSX)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 extern const char kBackShortcutBubbleShownCount[];
@@ -496,7 +496,7 @@ extern const char kAppWindowPlacement[];
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 
