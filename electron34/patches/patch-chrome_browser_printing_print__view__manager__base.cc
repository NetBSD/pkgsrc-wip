$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/printing/print_view_manager_base.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/printing/print_view_manager_base.cc
@@ -83,6 +83,20 @@ namespace printing {
 
 namespace {
 
+std::string PrintReasonFromPrintStatus(PrintViewManager::PrintStatus status) {
+  if (status == PrintViewManager::PrintStatus::kInvalid) {
+    return "Invalid printer settings";
+  } else if (status == PrintViewManager::PrintStatus::kCanceled) {
+    return "Print job canceled";
+  } else if (status == PrintViewManager::PrintStatus::kFailed) {
+    return "Print job failed";
+  }
+  return "";
+}
+
+using PrintSettingsCallback =
+    base::OnceCallback<void(std::unique_ptr<PrinterQuery>)>;
+
 void OnDidGetDefaultPrintSettings(
     scoped_refptr<PrintQueriesQueue> queue,
     bool want_pdf_settings,
@@ -91,9 +105,9 @@ void OnDidGetDefaultPrintSettings(
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
   if (printer_query->last_status() != mojom::ResultCode::kSuccess) {
-    if (!want_pdf_settings) {
+#if 0 // Electron does not use Chromium error dialogs
       ShowPrintErrorDialogForInvalidPrinterError();
-    }
+#endif
     std::move(callback).Run(nullptr);
     return;
   }
@@ -103,9 +117,9 @@ void OnDidGetDefaultPrintSettings(
   params->document_cookie = printer_query->cookie();
 
   if (!PrintMsgPrintParamsIsValid(*params)) {
-    if (!want_pdf_settings) {
+#if 0 // Electron does not use Chromium error dialogs
       ShowPrintErrorDialogForInvalidPrinterError();
-    }
+#endif
     std::move(callback).Run(nullptr);
     return;
   }
@@ -117,14 +131,14 @@ void OnDidGetDefaultPrintSettings(
 void OnDidScriptedPrint(
     scoped_refptr<PrintQueriesQueue> queue,
     std::unique_ptr<PrinterQuery> printer_query,
-    mojom::PrintManagerHost::ScriptedPrintCallback callback) {
+    mojom::PrintManagerHost::ScriptedPrintCallback callback,
+    base::OnceCallback<void()> cancel_job) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
   if (printer_query->last_status() != mojom::ResultCode::kSuccess ||
       !printer_query->settings().dpi()) {
-    // Notify user of the error, unless it was explicitly canceled.
-    if (printer_query->last_status() != mojom::ResultCode::kCanceled) {
-      ShowPrintErrorDialogForGenericError();
+    if (printer_query->last_status() == mojom::ResultCode::kCanceled) {
+      std::move(cancel_job).Run();
     }
     std::move(callback).Run(nullptr);
     return;
@@ -182,9 +196,11 @@ PrintViewManagerBase::PrintViewManagerBa
     : PrintManager(web_contents),
       queue_(g_browser_process->print_job_manager()->queue()) {
   DCHECK(queue_);
+#if 0
   Profile* profile =
       Profile::FromBrowserContext(web_contents->GetBrowserContext());
   printing_enabled_.Init(prefs::kPrintingEnabled, profile->GetPrefs());
+#endif
 }
 
 PrintViewManagerBase::~PrintViewManagerBase() {
@@ -208,12 +224,16 @@ void PrintViewManagerBase::DisableThirdP
 }
 #endif  // BUILDFLAG(IS_WIN) && BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
-bool PrintViewManagerBase::PrintNow(content::RenderFrameHost* rfh) {
+bool PrintViewManagerBase::PrintNow(content::RenderFrameHost* rfh,
+                                    base::Value::Dict settings,
+                                    CompletionCallback callback)  {
   if (!StartPrintCommon(rfh)) {
     return false;
   }
 
-  GetPrintRenderFrame(rfh)->PrintRequestedPages();
+  callback_ = std::move(callback);
+
+  GetPrintRenderFrame(rfh)->PrintRequestedPages(std::move(settings));
 
   for (auto& observer : GetTestObservers()) {
     observer.OnPrintNow(rfh);
@@ -295,7 +315,7 @@ void PrintViewManagerBase::PrintDocument
     const gfx::Size& page_size,
     const gfx::Rect& content_area,
     const gfx::Point& offsets) {
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
   if (content_analysis_before_printing_document_) {
     std::move(content_analysis_before_printing_document_)
         .Run(print_data, page_size, content_area, offsets);
@@ -342,12 +362,13 @@ void PrintViewManagerBase::OnDidUpdatePr
   }
   PRINTER_LOG(EVENT) << "Paper printable area updated for vendor id "
                      << print_settings->requested_media().vendor_id;
-  CompleteUpdatePrintSettings(std::move(job_settings),
+  CompleteUpdatePrintSettings(nullptr /* printer_query */, std::move(job_settings),
                               std::move(print_settings), std::move(callback));
 }
 #endif
 
 void PrintViewManagerBase::CompleteUpdatePrintSettings(
+    std::unique_ptr<PrinterQuery> printer_query,
     base::Value::Dict job_settings,
     std::unique_ptr<PrintSettings> print_settings,
     UpdatePrintSettingsCallback callback) {
@@ -355,7 +376,8 @@ void PrintViewManagerBase::CompleteUpdat
   settings->pages = GetPageRangesFromJobSettings(job_settings);
   settings->params = mojom::PrintParams::New();
   RenderParamsFromPrintSettings(*print_settings, settings->params.get());
-  settings->params->document_cookie = PrintSettings::NewCookie();
+  settings->params->document_cookie = printer_query ? printer_query->cookie()
+                                                    : PrintSettings::NewCookie();
   if (!PrintMsgPrintParamsIsValid(*settings->params)) {
     mojom::PrinterType printer_type = static_cast<mojom::PrinterType>(
         *job_settings.FindInt(kSettingPrinterType));
@@ -367,6 +389,10 @@ void PrintViewManagerBase::CompleteUpdat
     return;
   }
 
+  if (printer_query && printer_query->cookie() && printer_query->settings().dpi()) {
+    queue_->QueuePrinterQuery(std::move(printer_query));
+  }
+
   set_cookie(settings->params->document_cookie);
   std::move(callback).Run(std::move(settings));
 }
@@ -408,7 +434,9 @@ void PrintViewManagerBase::OnPrintSettin
       UnregisterSystemPrintClient();
     }
 #endif
+#if 0 // Electron does not use Chromium error dialogs
     ShowPrintErrorDialogForGenericError();
+#endif
     std::move(callback).Run(base::Value("Update settings failed"));
     return;
   }
@@ -437,7 +465,7 @@ void PrintViewManagerBase::StartLocalPri
     PrinterHandler::PrintCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
 
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
   // Populating `content_analysis_before_printing_document_` if needed should be
   // done first in this function's workflow, this way other code can check if
   // content analysis is going to happen and delay starting `print_job_` to
@@ -664,7 +692,7 @@ void PrintViewManagerBase::GetDefaultPri
 
 #if BUILDFLAG(ENABLE_OOP_PRINTING)
   if (ShouldPrintJobOop() &&
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
       !analyzing_content_ &&
 #endif
       !query_with_ui_client_id().has_value()) {
@@ -692,7 +720,7 @@ void PrintViewManagerBase::GetDefaultPri
 
   // Sometimes it is desired to get the PDF settings as opposed to the settings
   // of the default system print driver.
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
   bool want_pdf_settings = analyzing_content_;
 #else
   bool want_pdf_settings = false;
@@ -736,10 +764,7 @@ void PrintViewManagerBase::UpdatePrintSe
   // `job_settings` does not yet contain the rasterized PDF dpi, so if the user
   // has the print preference set, fetch it for use in
   // `PrintSettingsFromJobSettings()`.
-  content::BrowserContext* context =
-      web_contents() ? web_contents()->GetBrowserContext() : nullptr;
-  PrefService* prefs =
-      context ? Profile::FromBrowserContext(context)->GetPrefs() : nullptr;
+  PrefService* prefs = nullptr;
   if (prefs && prefs->HasPrefPath(prefs::kPrintRasterizePdfDpi)) {
     int value = prefs->GetInteger(prefs::kPrintRasterizePdfDpi);
     if (value > 0)
@@ -764,8 +789,22 @@ void PrintViewManagerBase::UpdatePrintSe
     }
   }
 
-#if BUILDFLAG(IS_WIN)
-  // TODO(crbug.com/40260379):  Remove this if the printable areas can be made
+  std::unique_ptr<PrinterQuery> query =
+      queue_->CreatePrinterQuery(GetCurrentTargetFrame()->GetGlobalId());
+  auto* query_ptr = query.get();
+  // We need to clone this before calling SetSettings because some environments
+  // evaluate job_settings.Clone() first, and some std::move(job_settings) first,
+  // for the former things work correctly but for the latter the cloned value is null.
+  auto job_settings_copy = job_settings.Clone();
+  query_ptr->SetSettings(
+      std::move(job_settings_copy),
+      base::BindOnce(&PrintViewManagerBase::CompleteUpdatePrintSettings,
+                     weak_ptr_factory_.GetWeakPtr(), std::move(query),
+                     std::move(job_settings), std::move(print_settings),
+                     std::move(callback)));
+
+#if 0 // See https://chromium-review.googlesource.com/412367
+  // TODO(crbug.com/1424368):  Remove this if the printable areas can be made
   // fully available from `PrintBackend::GetPrinterSemanticCapsAndDefaults()`
   // for in-browser queries.
   if (printer_type == mojom::PrinterType::kLocal) {
@@ -786,8 +825,6 @@ void PrintViewManagerBase::UpdatePrintSe
   }
 #endif
 
-  CompleteUpdatePrintSettings(std::move(job_settings),
-                              std::move(print_settings), std::move(callback));
 }
 
 void PrintViewManagerBase::SetAccessibilityTree(
@@ -803,7 +840,7 @@ void PrintViewManagerBase::SetAccessibil
 void PrintViewManagerBase::IsPrintingEnabled(
     IsPrintingEnabledCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
-  std::move(callback).Run(GetPrintingEnabledBooleanPref());
+  std::move(callback).Run(true);
 }
 
 void PrintViewManagerBase::ScriptedPrint(mojom::ScriptedPrintParamsPtr params,
@@ -829,7 +866,7 @@ void PrintViewManagerBase::ScriptedPrint
     return;
   }
 #endif
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
   std::optional<enterprise_connectors::ContentAnalysisDelegate::Data>
       scanning_data = enterprise_data_protection::GetPrintAnalysisData(
           web_contents(), enterprise_data_protection::PrintScanningContext::
@@ -859,11 +896,9 @@ void PrintViewManagerBase::PrintingFaile
   // destroyed.  In such cases the error notification to the user will
   // have already been displayed, and a second message should not be
   // shown.
-  if (print_job_ && print_job_->document() &&
-      print_job_->document()->cookie() == cookie) {
+#if 0 // Electron does not use Chromium error dialogs
     ShowPrintErrorDialogForGenericError();
-  }
-
+#endif
   ReleasePrinterQuery();
 }
 
@@ -875,15 +910,24 @@ void PrintViewManagerBase::RemoveTestObs
   test_observers_.RemoveObserver(&observer);
 }
 
+void PrintViewManagerBase::ShowInvalidPrinterSettingsError() {
+  if (!callback_.is_null()) {
+    printing_status_ = PrintStatus::kInvalid;
+    TerminatePrintJob(true);
+  }
+}
+
 void PrintViewManagerBase::RenderFrameHostStateChanged(
     content::RenderFrameHost* render_frame_host,
     content::RenderFrameHost::LifecycleState /*old_state*/,
     content::RenderFrameHost::LifecycleState new_state) {
+#if 0
   if (new_state == content::RenderFrameHost::LifecycleState::kActive &&
       render_frame_host->GetProcess()->IsPdf() &&
       !render_frame_host->GetMainFrame()->GetParentOrOuterDocument()) {
     GetPrintRenderFrame(render_frame_host)->ConnectToPdfRenderer();
   }
+#endif
 }
 
 void PrintViewManagerBase::RenderFrameDeleted(
@@ -925,13 +969,14 @@ void PrintViewManagerBase::SystemDialogC
   // System dialog was cancelled. Clean up the print job and notify the
   // BackgroundPrintingManager.
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+  printing_status_ = PrintStatus::kCanceled;
   ReleasePrinterQuery();
   TerminatePrintJob(true);
 }
 #endif
 
 bool PrintViewManagerBase::GetPrintingEnabledBooleanPref() const {
-  return printing_enabled_.GetValue();
+  return true;
 }
 
 void PrintViewManagerBase::OnDocDone(int job_id, PrintedDocument* document) {
@@ -945,18 +990,26 @@ void PrintViewManagerBase::OnJobDone() {
   // Printing is done, we don't need it anymore.
   // print_job_->is_job_pending() may still be true, depending on the order
   // of object registration.
-  printing_succeeded_ = true;
+  printing_status_ = PrintStatus::kSucceeded;
+  ReleasePrintJob();
+}
+
+void PrintViewManagerBase::UserInitCanceled() {
+  printing_status_ = PrintStatus::kCanceled;
   ReleasePrintJob();
 }
 
 void PrintViewManagerBase::OnCanceling() {
+  printing_status_ = PrintStatus::kCanceled;
   canceling_job_ = true;
 }
 
 void PrintViewManagerBase::OnFailed() {
   if (!canceling_job_)
+    printing_status_ = PrintStatus::kFailed;
+#if 0 // Electron does not use Chromium error dialogs
     ShowPrintErrorDialogForGenericError();
-
+#endif
   TerminatePrintJob(true);
 }
 
@@ -966,7 +1019,7 @@ bool PrintViewManagerBase::RenderAllMiss
 
   // Is the document already complete?
   if (print_job_->document() && print_job_->document()->IsComplete()) {
-    printing_succeeded_ = true;
+    printing_status_ = PrintStatus::kSucceeded;
     return true;
   }
 
@@ -1019,7 +1072,10 @@ bool PrintViewManagerBase::SetupNewPrint
 
   // Disconnect the current `print_job_`.
   auto weak_this = weak_ptr_factory_.GetWeakPtr();
-  DisconnectFromCurrentPrintJob();
+  if (callback_.is_null()) {
+    // Disconnect the current |print_job_| only when calling window.print()
+    DisconnectFromCurrentPrintJob();
+  }
   if (!weak_this)
     return false;
 
@@ -1039,7 +1095,7 @@ bool PrintViewManagerBase::SetupNewPrint
 #endif
   print_job_->AddObserver(*this);
 
-  printing_succeeded_ = false;
+  printing_status_ = PrintStatus::kUnknown;
   return true;
 }
 
@@ -1097,7 +1153,7 @@ void PrintViewManagerBase::ReleasePrintJ
     // Ensure that any residual registration of printing client is released.
     // This might be necessary in some abnormal cases, such as the associated
     // render process having terminated.
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
     if (!analyzing_content_) {
       UnregisterSystemPrintClient();
     }
@@ -1107,6 +1163,11 @@ void PrintViewManagerBase::ReleasePrintJ
   }
 #endif
 
+  if (!callback_.is_null()) {
+    bool success = printing_status_ == PrintStatus::kSucceeded;
+    std::move(callback_).Run(success, PrintReasonFromPrintStatus(printing_status_));
+  }
+
   if (!print_job_)
     return;
 
@@ -1114,7 +1175,7 @@ void PrintViewManagerBase::ReleasePrintJ
     // printing_rfh_ should only ever point to a RenderFrameHost with a live
     // RenderFrame.
     DCHECK(rfh->IsRenderFrameLive());
-    GetPrintRenderFrame(rfh)->PrintingDone(printing_succeeded_);
+    GetPrintRenderFrame(rfh)->PrintingDone(printing_status_ == PrintStatus::kSucceeded);
   }
 
   print_job_->RemoveObserver(*this);
@@ -1156,7 +1217,7 @@ bool PrintViewManagerBase::RunInnerMessa
 }
 
 bool PrintViewManagerBase::OpportunisticallyCreatePrintJob(int cookie) {
-  if (print_job_)
+  if (print_job_ && print_job_->document())
     return true;
 
   if (!cookie) {
@@ -1179,7 +1240,7 @@ bool PrintViewManagerBase::Opportunistic
     return false;
   }
 
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
   // Don't start printing if enterprise checks are being performed to check if
   // printing is allowed, or if content analysis is going to take place right
   // before starting `print_job_`.
@@ -1310,6 +1371,8 @@ void PrintViewManagerBase::CompleteScrip
   auto callback_wrapper = base::BindOnce(
       &PrintViewManagerBase::ScriptedPrintReply, weak_ptr_factory_.GetWeakPtr(),
       std::move(callback), render_process_host->GetID());
+  auto cancel_job_wrapper = base::BindOnce(
+      &PrintViewManagerBase::UserInitCanceled, weak_ptr_factory_.GetWeakPtr());
 #if BUILDFLAG(IS_WIN) && BUILDFLAG(GOOGLE_CHROME_BRANDING)
   DisableThirdPartyBlocking();
 #endif
@@ -1324,10 +1387,10 @@ void PrintViewManagerBase::CompleteScrip
       params->expected_pages_count, params->has_selection, params->margin_type,
       params->is_scripted, !render_process_host->IsPdf(),
       base::BindOnce(&OnDidScriptedPrint, queue_, std::move(printer_query),
-                     std::move(callback_wrapper)));
+                     std::move(callback_wrapper), std::move(cancel_job_wrapper)));
 }
 
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
 void PrintViewManagerBase::CompletePrintDocumentAfterContentAnalysis(
     scoped_refptr<base::RefCountedMemory> print_data,
     const gfx::Size& page_size,
