$NetBSD$

--- chrome/browser/ui/views/first_run_dialog.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -114,8 +114,10 @@ void FirstRunDialog::Done() {
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(report_crashes_->GetChecked(),
                                        base::Bind(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->GetChecked())
     shell_integration::SetAsDefaultBrowser();
