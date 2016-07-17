$NetBSD$

--- chrome/browser/ui/views/first_run_dialog.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -116,12 +116,16 @@ views::View* FirstRunDialog::CreateExtra
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   if (report_crashes_ && report_crashes_->checked()) {
     if (GoogleUpdateSettings::SetCollectStatsConsent(true))
       breakpad::InitCrashReporter(std::string());
-  } else {
+  } else
+#else
+  {
     GoogleUpdateSettings::SetCollectStatsConsent(false);
   }
+#endif
 
   if (make_default_ && make_default_->checked())
     shell_integration::SetAsDefaultBrowser();
