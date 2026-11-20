$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2026-11-20 11:41:22.319814045 +0000
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -680,14 +680,13 @@ bool ContextMenuController::ShowContextM
     if (potential_image_node != nullptr &&
         IsA<HTMLCanvasElement>(potential_image_node)) {
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
+      const auto* canvas = To<HTMLCanvasElement>(potential_image_node);
+      data.has_image_contents = canvas->OriginClean();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
-      data.has_image_contents =
-          !To<HTMLCanvasElement>(potential_image_node)->IsWebGPU();
-#else
-      data.has_image_contents = true;
+      data.has_image_contents &= !canvas->IsWebGPU();
 #endif
     } else if (potential_image_node != nullptr &&
                !HitTestResult::AbsoluteImageURL(potential_image_node)
