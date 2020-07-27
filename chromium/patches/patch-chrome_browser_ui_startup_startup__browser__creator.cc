$NetBSD$

--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -303,7 +303,7 @@ bool IsSilentLaunchEnabled(const base::C
 // true, send a warning if guest mode is requested but not allowed by policy.
 bool IsGuestModeEnforced(const base::CommandLine& command_line,
                          bool show_warning) {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   PrefService* service = g_browser_process->local_state();
   DCHECK(service);
 
@@ -687,7 +687,7 @@ bool StartupBrowserCreator::ProcessCmdLi
   }
 #endif  // OS_CHROMEOS
 
-#if defined(TOOLKIT_VIEWS) && defined(USE_X11)
+#if defined(TOOLKIT_VIEWS) && defined(USE_X11) && !defined(OS_BSD)
   // TODO(https://crbug.com/1097696): make it available on ozone/linux.
   if (!features::IsUsingOzonePlatform())
     ui::TouchFactory::SetTouchDeviceListFromCommandLine();
