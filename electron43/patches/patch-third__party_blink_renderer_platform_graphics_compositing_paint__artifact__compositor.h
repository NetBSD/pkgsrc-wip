$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/graphics/compositing/paint_artifact_compositor.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/compositing/paint_artifact_compositor.h
@@ -231,8 +231,6 @@ class PLATFORM_EXPORT PaintArtifactCompo
   void ShowDebugData();
 #endif
 
-  void ForAllContentLayersForTesting(
-      base::FunctionRef<void(ContentLayerClientImpl*)> func) const;
   // Returns the ith ContentLayerClientImpl for testing.
   ContentLayerClientImpl* ContentLayerClientForTesting(wtf_size_t i) const;
 
