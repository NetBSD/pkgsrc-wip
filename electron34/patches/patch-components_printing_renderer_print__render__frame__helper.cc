$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/printing/renderer/print_render_frame_helper.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/printing/renderer/print_render_frame_helper.cc
@@ -52,6 +52,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "printing/page_number.h"
 #include "printing/print_job_constants.h"
+#include "printing/print_settings.h"
 #include "printing/units.h"
 #include "services/metrics/public/cpp/ukm_source_id.h"
 #include "third_party/blink/public/common/associated_interfaces/associated_interface_provider.h"
@@ -1227,14 +1228,14 @@ void PrintRenderFrameHelper::ScriptedPri
   }
 
   print_in_progress_ = true;
-
   auto weak_this = weak_ptr_factory_.GetWeakPtr();
   web_frame->DispatchBeforePrintEvent(/*print_client=*/nullptr);
   if (!weak_this) {
     return;
   }
 
-  Print(web_frame, blink::WebNode(), PrintRequestType::kScripted);
+  Print(web_frame, blink::WebNode(), PrintRequestType::kScripted,
+        base::Value::Dict());
   if (!weak_this) {
     return;
   }
@@ -1265,12 +1266,14 @@ void PrintRenderFrameHelper::BindPrintRe
   receivers_.Add(this, std::move(receiver));
 }
 
-void PrintRenderFrameHelper::PrintRequestedPages() {
-  PrintRequestedPagesInternal(/*already_notified_frame=*/false);
+void PrintRenderFrameHelper::PrintRequestedPages(base::Value::Dict settings) {
+  PrintRequestedPagesInternal(/*already_notified_frame=*/false,
+                              std::move(settings));
 }
 
 void PrintRenderFrameHelper::PrintRequestedPagesInternal(
-    bool already_notified_frame) {
+    bool already_notified_frame,
+    base::Value::Dict settings) {
   ScopedIPC scoped_ipc(weak_ptr_factory_.GetWeakPtr());
   if (ipc_nesting_level_ > kAllowedIpcDepthForPrint) {
     return;
@@ -1287,9 +1290,10 @@ void PrintRenderFrameHelper::PrintReques
 
     is_loading_ = frame->WillPrintSoon();
     if (is_loading_) {
-      on_stop_loading_closure_ = base::BindOnce(
-          &PrintRenderFrameHelper::PrintRequestedPagesInternal,
-          weak_ptr_factory_.GetWeakPtr(), /*already_notified_frame=*/true);
+      on_stop_loading_closure_ =
+          base::BindOnce(&PrintRenderFrameHelper::PrintRequestedPagesInternal,
+                         weak_ptr_factory_.GetWeakPtr(),
+                         /*already_notified_frame=*/true, std::move(settings));
       SetupOnStopLoadingTimeout();
       return;
     }
@@ -1299,7 +1303,7 @@ void PrintRenderFrameHelper::PrintReques
   // plugin node and print that instead.
   auto plugin = delegate_->GetPdfElement(frame);
 
-  Print(frame, plugin, PrintRequestType::kRegular);
+  Print(frame, plugin, PrintRequestType::kRegular, std::move(settings));
 
   if (render_frame_gone_) {
     return;
@@ -1456,6 +1460,8 @@ void PrintRenderFrameHelper::PrintPrevie
   if (ipc_nesting_level_ > kAllowedIpcDepthForPrint)
     return;
 
+  blink::WebLocalFrame* frame = render_frame()->GetWebFrame();
+  print_preview_context_.InitWithFrame(frame);
   print_preview_context_.OnPrintPreview();
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -2063,17 +2069,19 @@ void PrintRenderFrameHelper::PrintNode(c
 
 void PrintRenderFrameHelper::Print(blink::WebLocalFrame* frame,
                                    const blink::WebNode& node,
-                                   PrintRequestType print_request_type) {
+                                   PrintRequestType print_request_type,
+                                   base::Value::Dict settings) {
   // If still not finished with earlier print request simply ignore.
   if (prep_frame_view_)
     return;
 
+  bool silent = settings.FindBool("silent").value_or(false);
   FrameReference frame_ref(frame);
 
-  if (!InitPrintSettings(frame, node)) {
+  if (!InitPrintSettings(frame, node, std::move(settings))) {
     // Browser triggered this code path. It already knows about the failure.
     notify_browser_of_print_failure_ = false;
-
+    GetPrintManagerHost()->ShowInvalidPrinterSettingsError();
     DidFinishPrinting(PrintingResult::kFailPrintInit);
     return;
   }
@@ -2094,8 +2102,15 @@ void PrintRenderFrameHelper::Print(blink
         print_pages_params_->params->print_scaling_option;
 
     auto self = weak_ptr_factory_.GetWeakPtr();
-    mojom::PrintPagesParamsPtr print_settings = GetPrintSettingsFromUser(
+    mojom::PrintPagesParamsPtr print_settings;
+
+    if (silent) {
+      print_settings = mojom::PrintPagesParams::New();
+      print_settings->params = print_pages_params_->params->Clone();
+    } else {
+      print_settings = GetPrintSettingsFromUser(
         frame_ref.GetFrame(), node, expected_page_count, print_request_type);
+    }
     // Check if `this` is still valid.
     if (!self)
       return;
@@ -2360,29 +2375,44 @@ void PrintRenderFrameHelper::IPCProcesse
 }
 
 bool PrintRenderFrameHelper::InitPrintSettings(blink::WebLocalFrame* frame,
-                                               const blink::WebNode& node) {
+                                               const blink::WebNode& node,
+                                               base::Value::Dict new_settings) {
   // Reset to default values.
   ignore_css_margins_ = false;
 
-  mojom::PrintPagesParams settings;
-  GetPrintManagerHost()->GetDefaultPrintSettings(&settings.params);
+  mojom::PrintPagesParamsPtr settings;
+  if (new_settings.empty()) {
+    settings = mojom::PrintPagesParams::New();
+    settings->params = mojom::PrintParams::New();
+    GetPrintManagerHost()->GetDefaultPrintSettings(&settings->params);
+  } else {
+    GetPrintManagerHost()->UpdatePrintSettings(
+      std::move(new_settings), &settings);
+  }
 
   // Check if the printer returned any settings, if the settings are null,
   // assume there are no printer drivers configured. So safely terminate.
-  if (!settings.params) {
+  if (!settings || !settings->params) {
     // Caller will reset `print_pages_params_`.
     return false;
   }
 
-  bool center_on_paper = !IsPrintingPdfFrame(frame, node);
-  settings.params->print_scaling_option =
-      center_on_paper ? mojom::PrintScalingOption::kCenterShrinkToFitPaper
-                      : mojom::PrintScalingOption::kSourceSize;
-  RecordDebugEvent(settings.params->printed_doc_type ==
+  bool silent = new_settings.FindBool("silent").value_or(false);
+  if (silent) {
+    settings->params->print_scaling_option = mojom::PrintScalingOption::kFitToPrintableArea;
+  } else {
+    const auto plugin_node = delegate_->GetPdfElement(frame);
+    const bool center_on_paper = !IsPrintingPdfFrame(frame, plugin_node);
+    settings->params->print_scaling_option =
+        center_on_paper ? mojom::PrintScalingOption::kCenterShrinkToFitPaper
+                        : mojom::PrintScalingOption::kSourceSize;
+  }
+
+  RecordDebugEvent(settings->params->printed_doc_type ==
                            mojom::SkiaDocumentType::kMSKP
                        ? DebugEvent::kSetPrintSettings5
                        : DebugEvent::kSetPrintSettings6);
-  SetPrintPagesParams(settings);
+  SetPrintPagesParams(*settings);
   return true;
 }
 
