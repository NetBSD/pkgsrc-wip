$NetBSD$

--- chrome/test/base/chrome_test_launcher.cc.orig	2020-07-08 21:40:37.000000000 +0000
+++ chrome/test/base/chrome_test_launcher.cc
@@ -47,7 +47,7 @@
 #include "ui/base/test/ui_controls_aura.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "chrome/app/chrome_crash_reporter_client.h"
 #endif
 
@@ -61,7 +61,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 #include "chrome/browser/first_run/scoped_relaunch_chrome_browser_override.h"
 #include "chrome/browser/upgrade_detector/installed_version_poller.h"
 #include "testing/gtest/include/gtest/gtest.h"
@@ -79,7 +79,7 @@ int ChromeTestSuiteRunner::RunTestSuite(
   content::ContentTestSuiteBase::RegisterInProcessThreads();
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   InstalledVersionPoller::ScopedDisableForTesting disable_polling(
       InstalledVersionPoller::MakeScopedDisableForTesting());
 #endif
@@ -201,7 +201,7 @@ int LaunchChromeTests(size_t parallel_jo
   if (command_line.HasSwitch(switches::kLaunchAsBrowser))
     sampling_profiler = std::make_unique<MainThreadStackSamplingProfiler>();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   ChromeCrashReporterClient::Create();
 #elif defined(OS_WIN)
   // We leak this pointer intentionally. The crash client needs to outlive
@@ -229,7 +229,7 @@ int LaunchChromeTests(size_t parallel_jo
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   // Cause a test failure for any test that triggers an unexpected relaunch.
   // Tests that fail here should likely be restructured to put the "before
   // relaunch" code into a PRE_ test with its own
