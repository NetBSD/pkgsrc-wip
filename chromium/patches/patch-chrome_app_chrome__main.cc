$NetBSD$

--- chrome/app/chrome_main.cc.orig	2020-06-25 09:31:20.000000000 +0000
+++ chrome/app/chrome_main.cc
@@ -109,7 +109,7 @@ int ChromeMain(int argc, const char** ar
   MainThreadStackSamplingProfiler scoped_sampling_profiler;
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
