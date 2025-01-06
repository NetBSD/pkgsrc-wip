$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accelerated_widget_mac/display_ca_layer_tree.mm.orig	2024-10-18 12:35:11.560735000 +0000
+++ ui/accelerated_widget_mac/display_ca_layer_tree.mm
@@ -121,6 +121,7 @@ void DisplayCALayerTree::UpdateCALayerTr
 }
 
 void DisplayCALayerTree::GotCALayerFrame(uint32_t ca_context_id) {
+#if !IS_MAS_BUILD()
   // Early-out if the remote layer has not changed.
   if (remote_layer_.contextId == ca_context_id) {
     return;
@@ -150,6 +151,9 @@ void DisplayCALayerTree::GotCALayerFrame
     [io_surface_layer_ removeFromSuperlayer];
     io_surface_layer_ = nil;
   }
+#else
+  NOTREACHED() << "Remote layer is being used in MAS build";
+#endif
 }
 
 void DisplayCALayerTree::GotIOSurfaceFrame(
