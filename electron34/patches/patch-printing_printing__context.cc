$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ printing/printing_context.cc
@@ -154,7 +154,6 @@ void PrintingContext::UsePdfSettings() {
 
 mojom::ResultCode PrintingContext::UpdatePrintSettings(
     base::Value::Dict job_settings) {
-  ResetSettings();
   {
     std::unique_ptr<PrintSettings> settings =
         PrintSettingsFromJobSettings(job_settings);
