$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accelerated_widget_mac/display_ca_layer_tree.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/accelerated_widget_mac/display_ca_layer_tree.mm
@@ -12,6 +12,7 @@
 #include "base/mac/mac_util.h"
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
+#include "electron/mas.h"
 #include "ui/base/cocoa/animation_utils.h"
 #include "ui/base/cocoa/remote_layer_api.h"
 #include "ui/gfx/geometry/dip_util.h"
@@ -121,6 +122,7 @@ void DisplayCALayerTree::UpdateCALayerTr
 }
 
 void DisplayCALayerTree::GotCALayerFrame(uint32_t ca_context_id) {
+#if !IS_MAS_BUILD()
   // Early-out if the remote layer has not changed.
   if (remote_layer_.contextId == ca_context_id) {
     return;
@@ -150,6 +152,9 @@ void DisplayCALayerTree::GotCALayerFrame
     [io_surface_layer_ removeFromSuperlayer];
     io_surface_layer_ = nil;
   }
+#else
+  NOTREACHED() << "Remote layer is being used in MAS build";
+#endif
 }
 
 void DisplayCALayerTree::GotIOSurfaceFrame(
