$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/printing/print_view_manager_base.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/printing/print_view_manager_base.h
@@ -52,6 +52,8 @@ class PrinterQuery;
 // rollout.
 BASE_DECLARE_FEATURE(kCheckPrintRfhIsActive);
 
+using CompletionCallback = base::OnceCallback<void(bool, const std::string&)>;
+
 // Base class for managing the print commands for a WebContents.
 class PrintViewManagerBase : public PrintManager, public PrintJob::Observer {
  public:
@@ -87,7 +89,9 @@ class PrintViewManagerBase : public Prin
   // Prints the current document immediately. Since the rendering is
   // asynchronous, the actual printing will not be completed on the return of
   // this function. Returns false if printing is impossible at the moment.
-  virtual bool PrintNow(content::RenderFrameHost* rfh);
+  virtual bool PrintNow(content::RenderFrameHost* rfh,
+                        base::Value::Dict settings = {},
+                        CompletionCallback callback = {});
 
   // Like PrintNow(), but for the node under the context menu, instead of the
   // entire frame.
@@ -141,8 +145,10 @@ class PrintViewManagerBase : public Prin
   void IsPrintingEnabled(IsPrintingEnabledCallback callback) override;
   void ScriptedPrint(mojom::ScriptedPrintParamsPtr params,
                      ScriptedPrintCallback callback) override;
+  void ShowInvalidPrinterSettingsError() override;
   void PrintingFailed(int32_t cookie,
                       mojom::PrintFailureReason reason) override;
+  void UserInitCanceled();
 
   // Adds and removes observers for `PrintViewManagerBase` events. The order in
   // which notifications are sent to observers is undefined. Observers must be
@@ -150,6 +156,14 @@ class PrintViewManagerBase : public Prin
   void AddTestObserver(TestObserver& observer);
   void RemoveTestObserver(TestObserver& observer);
 
+  enum class PrintStatus {
+    kSucceeded,
+    kCanceled,
+    kFailed,
+    kInvalid,
+    kUnknown
+  };
+
  protected:
 #if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
   using PrintDocumentCallback =
@@ -229,7 +243,7 @@ class PrintViewManagerBase : public Prin
                                      mojom::ScriptedPrintParamsPtr params,
                                      ScriptedPrintCallback callback);
 
-#if BUILDFLAG(ENTERPRISE_CONTENT_ANALYSIS)
+#if 0
   // Helper method bound to `content_analysis_before_printing_document_` when
   // content analysis should happen right before the document is to be printed.
   // This method is virtual for testing purposes.
@@ -293,6 +307,7 @@ class PrintViewManagerBase : public Prin
                                 bool success);
 #endif
   void CompleteUpdatePrintSettings(
+      std::unique_ptr<PrinterQuery> printer_query,
       base::Value::Dict job_settings,
       std::unique_ptr<PrintSettings> print_settings,
       UpdatePrintSettingsCallback callback);
@@ -387,8 +402,11 @@ class PrintViewManagerBase : public Prin
   // The current RFH that is printing with a system printing dialog.
   raw_ptr<content::RenderFrameHost> printing_rfh_ = nullptr;
 
+  // Respond with success of the print job.
+  CompletionCallback callback_;
+
   // Indication of success of the print job.
-  bool printing_succeeded_ = false;
+  PrintStatus printing_status_ = PrintStatus::kUnknown;
 
   // Indication that the job is getting canceled.
   bool canceling_job_ = false;
