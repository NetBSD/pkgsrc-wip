$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/printing/renderer/print_render_frame_helper.h.orig	2024-10-18 12:34:07.565981900 +0000
+++ components/printing/renderer/print_render_frame_helper.h
@@ -251,7 +251,7 @@ class PrintRenderFrameHelper
       mojo::PendingAssociatedReceiver<mojom::PrintRenderFrame> receiver);
 
   // printing::mojom::PrintRenderFrame:
-  void PrintRequestedPages() override;
+  void PrintRequestedPages(base::Value::Dict settings) override;
   void PrintWithParams(mojom::PrintPagesParamsPtr params,
                        PrintWithParamsCallback callback) override;
 #if BUILDFLAG(ENABLE_PRINT_PREVIEW)
@@ -318,7 +318,8 @@ class PrintRenderFrameHelper
   // WARNING: |this| may be gone after this method returns.
   void Print(blink::WebLocalFrame* frame,
              const blink::WebNode& node,
-             PrintRequestType print_request_type);
+             PrintRequestType print_request_type,
+             base::Value::Dict settings = {});
 
   // Notification when printing is done - signal tear-down/free resources.
   void DidFinishPrinting(PrintingResult result);
@@ -328,7 +329,8 @@ class PrintRenderFrameHelper
   // Initialize print page settings with default settings.
   // Used only for native printing workflow.
   bool InitPrintSettings(blink::WebLocalFrame* frame,
-                         const blink::WebNode& node);
+                         const blink::WebNode& node,
+                         base::Value::Dict new_settings);
 
   // Calculate number of pages in source document.
   uint32_t CalculateNumberOfPages(blink::WebLocalFrame* frame,
@@ -625,7 +627,8 @@ class PrintRenderFrameHelper
   };
 
   void SetupOnStopLoadingTimeout();
-  void PrintRequestedPagesInternal(bool already_notified_frame);
+  void PrintRequestedPagesInternal(bool already_notified_frame,
+                                   base::Value::Dict settings);
 
   ScriptingThrottler scripting_throttler_;
 
