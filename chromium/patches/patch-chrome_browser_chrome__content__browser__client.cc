$NetBSD$

--- chrome/browser/chrome_content_browser_client.cc.orig	2020-07-24 02:37:46.000000000 +0000
+++ chrome/browser/chrome_content_browser_client.cc
@@ -410,7 +410,7 @@
 #include "components/user_manager/user.h"
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -471,7 +471,7 @@
 #endif  //  !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #include "services/service_manager/sandbox/features.h"
 #endif
@@ -504,7 +504,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -819,11 +819,13 @@ breakpad::CrashHandlerHostLinux* CreateC
 }
 
 int GetCrashSignalFD(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (crash_reporter::IsCrashpadEnabled()) {
     int fd;
     pid_t pid;
     return crash_reporter::GetHandlerSocket(&fd, &pid) ? fd : -1;
   }
+#endif
 
   // Extensions have the same process type as renderers.
   if (command_line.HasSwitch(extensions::switches::kExtensionProcess)) {
@@ -1330,7 +1332,7 @@ ChromeContentBrowserClient::CreateBrowse
 #elif defined(OS_CHROMEOS)
   main_parts = std::make_unique<chromeos::ChromeBrowserMainPartsChromeos>(
       parameters, startup_data_);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts =
       std::make_unique<ChromeBrowserMainPartsLinux>(parameters, startup_data_);
 #elif defined(OS_ANDROID)
@@ -1356,7 +1358,7 @@ ChromeContentBrowserClient::CreateBrowse
     // Construct additional browser parts. Stages are called in the order in
     // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -2117,6 +2119,8 @@ void ChromeContentBrowserClient::AppendE
 #elif defined(OS_POSIX)
 #if defined(OS_ANDROID)
   bool enable_crash_reporter = true;
+#elif defined(OS_BSD)
+  bool enable_crash_reporter = false;
 #else
   bool enable_crash_reporter = false;
   if (crash_reporter::IsCrashpadEnabled()) {
@@ -2414,7 +2418,7 @@ void ChromeContentBrowserClient::AppendE
   StackSamplingConfiguration::Get()->AppendCommandLineSwitchForChildProcess(
       process_type, command_line);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (browser_command_line.HasSwitch(switches::kEnableThreadInstructionCount) &&
       command_line->HasSwitch(service_manager::switches::kNoSandbox)) {
@@ -3686,7 +3690,7 @@ void ChromeContentBrowserClient::GetAddi
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -3807,7 +3811,7 @@ bool ChromeContentBrowserClient::IsRende
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 bool ShouldEnableAudioSandbox(const policy::PolicyMap& policies) {
   const base::Value* audio_sandbox_enabled_policy_value =
       policies.GetValue(policy::key::kAudioSandboxEnabled);
@@ -3825,7 +3829,7 @@ bool ShouldEnableAudioSandbox(const poli
 
 void ChromeContentBrowserClient::WillStartServiceManager() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   if (startup_data_) {
     auto* chrome_feature_list_creator =
         startup_data_->chrome_feature_list_creator();
@@ -4071,7 +4075,7 @@ ChromeContentBrowserClient::CreateThrott
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   MaybeAddThrottle(browser_switcher::BrowserSwitcherNavigationThrottle::
                        MaybeCreateThrottleFor(handle),
                    &throttles);
