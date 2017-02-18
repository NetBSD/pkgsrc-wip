$NetBSD$

--- chrome/browser/ui/views/first_run_dialog.cc.orig	2017-02-02 02:02:50.000000000 +0000
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -40,8 +40,10 @@ using views::GridLayout;
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#ifndef OS_BSD
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
