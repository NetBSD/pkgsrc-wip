$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/graphics/compositing/paint_artifact_compositor.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/compositing/paint_artifact_compositor.cc
@@ -1524,15 +1524,6 @@ void PaintArtifactCompositor::ShowDebugD
 }
 #endif
 
-void PaintArtifactCompositor::ForAllContentLayersForTesting(
-    base::FunctionRef<void(ContentLayerClientImpl*)> func) const {
-  for (auto& pending_layer : pending_layers_) {
-    if (auto* client = pending_layer.GetContentLayerClient()) {
-      func(client);
-    }
-  }
-}
-
 ContentLayerClientImpl* PaintArtifactCompositor::ContentLayerClientForTesting(
     wtf_size_t i) const {
   for (auto& pending_layer : pending_layers_) {
