$NetBSD$

--- chrome/browser/chrome_browser_main.cc.orig	2020-07-24 02:37:46.000000000 +0000
+++ chrome/browser/chrome_browser_main.cc
@@ -207,7 +207,7 @@
 #include "components/arc/metrics/stability_metrics_manager.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -245,7 +245,7 @@
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #include "chrome/browser/metrics/desktop_session_duration/touch_mode_stats_tracker.h"
 #include "chrome/browser/profiles/profile_activity_metrics_recorder.h"
@@ -924,7 +924,7 @@ int ChromeBrowserMainParts::PreCreateThr
       AddFirstRunNewTabs(browser_creator_.get(), master_prefs_->new_tabs);
     }
 
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     // Create directory for user-level Native Messaging manifest files. This
     // makes it less likely that the directory will be created by third-party
     // software with incorrect owner or permission. See crbug.com/725513 .
@@ -955,7 +955,7 @@ int ChromeBrowserMainParts::PreCreateThr
 #endif  // defined(OS_MACOSX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   metrics::DesktopSessionDurationTracker::Initialize();
   ProfileActivityMetricsRecorder::Initialize();
   TouchModeStatsTracker::Initialize(
@@ -1111,6 +1111,7 @@ void ChromeBrowserMainParts::PostBrowser
       base::TimeDelta::FromMinutes(1));
 
 #if !defined(OS_ANDROID)
+#if !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebUsb)) {
     web_usb_detector_.reset(new WebUsbDetector());
     content::GetUIThreadTaskRunner({base::TaskPriority::BEST_EFFORT})
@@ -1118,6 +1119,7 @@ void ChromeBrowserMainParts::PostBrowser
                    base::BindOnce(&WebUsbDetector::Initialize,
                                   base::Unretained(web_usb_detector_.get())));
   }
+#endif
   if (base::FeatureList::IsEnabled(features::kTabMetricsLogging)) {
     // Initialize the TabActivityWatcher to begin logging tab activity events.
     resource_coordinator::TabActivityWatcher::GetInstance();
