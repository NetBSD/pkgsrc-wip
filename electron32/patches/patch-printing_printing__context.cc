$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_context.cc.orig	2024-10-18 12:34:31.741884500 +0000
+++ printing/printing_context.cc
@@ -154,7 +154,6 @@ void PrintingContext::UsePdfSettings() {
 
 mojom::ResultCode PrintingContext::UpdatePrintSettings(
     base::Value::Dict job_settings) {
-  ResetSettings();
   {
     std::unique_ptr<PrintSettings> settings =
         PrintSettingsFromJobSettings(job_settings);
