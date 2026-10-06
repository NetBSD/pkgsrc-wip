$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/printing/printer_query.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/printing/printer_query.cc
@@ -341,7 +341,7 @@ void PrinterQuery::UpdatePrintSettings(b
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         printer_name, print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && BUILDFLAG(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
@@ -355,17 +355,19 @@ void PrinterQuery::UpdatePrintSettings(b
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
   }
 
-  mojom::ResultCode result;
   {
 #if BUILDFLAG(IS_WIN)
     // Blocking is needed here because Windows printer drivers are oftentimes
     // not thread-safe and have to be accessed on the UI thread.
     base::ScopedAllowBlocking allow_blocking;
 #endif
-    result = printing_context_->UpdatePrintSettings(std::move(new_settings));
+    // Reset settings from previous print job
+    printing_context_->ResetSettings();
+    mojom::ResultCode result_code = printing_context_->UseDefaultSettings();
+    if (result_code == mojom::ResultCode::kSuccess)
+      result_code = printing_context_->UpdatePrintSettings(std::move(new_settings));
+    InvokeSettingsCallback(std::move(callback), result_code);
   }
-
-  InvokeSettingsCallback(std::move(callback), result);
 }
 
 #if BUILDFLAG(IS_CHROMEOS)
