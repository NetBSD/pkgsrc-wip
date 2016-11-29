$NetBSD$

--- chrome/browser/ui/views/first_run_dialog.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -35,8 +35,10 @@ using views::GridLayout;
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#ifndef OS_BSD
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
