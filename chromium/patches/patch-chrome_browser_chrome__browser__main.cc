$NetBSD: patch-chrome_browser_chrome__browser__main.cc,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/chrome_browser_main.cc
@@ -249,15 +249,15 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -290,14 +290,14 @@
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #include "chrome/browser/metrics/desktop_session_duration/touch_mode_stats_tracker.h"
 #include "chrome/browser/profiles/profile_activity_metrics_recorder.h"
 #include "ui/base/pointer/touch_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_metrics.h"  // nogncheck
 #include "chrome/browser/headless/headless_mode_util.h"     // nogncheck
 #include "components/headless/select_file_dialog/headless_select_file_dialog.h"
@@ -365,14 +365,14 @@
 #endif  // BUILDFLAG(IS_WIN) && BUILDFLAG(USE_BROWSER_SPELLCHECKER)
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "sql/database.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
 
 namespace {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kMediaHistoryDatabaseName[] =
     FILE_PATH_LITERAL("Media History");
 
@@ -537,7 +537,7 @@ void ProcessSingletonNotificationCallbac
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as a command line switch by another
   // browser process. This also removes the switch after use to prevent any side
   // effects of leaving it in the command line after this point.
@@ -1114,7 +1114,7 @@ int ChromeBrowserMainParts::PreCreateThr
       browser_creator_->AddFirstRunTabs(master_prefs_->new_tabs);
     }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Create directory for user-level Native Messaging manifest files. This
     // makes it less likely that the directory will be created by third-party
     // software with incorrect owner or permission. See crbug.com/725513 .
@@ -1162,7 +1162,7 @@ int ChromeBrowserMainParts::PreCreateThr
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   metrics::DesktopSessionDurationTracker::Initialize();
   ProfileActivityMetricsRecorder::Initialize();
   TouchModeStatsTracker::Initialize(
@@ -1358,7 +1358,7 @@ void ChromeBrowserMainParts::PostProfile
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Delete the media history database if it still exists.
   // TODO(crbug.com/40177301): Remove this.
   base::ThreadPool::PostTask(
@@ -1407,7 +1407,7 @@ void ChromeBrowserMainParts::PostProfile
       *UrlLanguageHistogramFactory::GetForBrowserContext(profile));
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::ReportHeadlessActionMetrics();
   }
@@ -1516,7 +1516,7 @@ int ChromeBrowserMainParts::PreMainMessa
   // In headless mode provide alternate SelectFileDialog factory overriding
   // any platform specific SelectFileDialog implementation that may have been
   // set.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode()) {
     headless::HeadlessSelectFileDialogFactory::SetUp();
   }
@@ -2073,7 +2073,7 @@ bool ChromeBrowserMainParts::ProcessSing
 
   // Drop the request if headless mode is in effect or the request is from
   // a headless Chrome process.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (headless::IsHeadlessMode() ||
       command_line.HasSwitch(switches::kHeadless)) {
     return false;
