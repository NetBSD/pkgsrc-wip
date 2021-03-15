$NetBSD$

--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc
@@ -322,7 +322,7 @@ void HeadlessContentMainDelegate::InitCr
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -405,7 +405,7 @@ int HeadlessContentMainDelegate::RunProc
 }
 #endif  // !defined(CHROME_MULTIPLE_DLL_CHILD)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
