$NetBSD$

--- headless/lib/headless_content_main_delegate.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ headless/lib/headless_content_main_delegate.cc
@@ -324,7 +324,7 @@ void HeadlessContentMainDelegate::InitCr
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -405,7 +405,7 @@ int HeadlessContentMainDelegate::RunProc
   return 0;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
