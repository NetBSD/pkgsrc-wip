$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accelerated_widget_mac/ca_layer_tree_coordinator.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/accelerated_widget_mac/ca_layer_tree_coordinator.h
@@ -7,6 +7,7 @@
 
 #include <queue>
 
+#include "electron/mas.h"
 #include "ui/accelerated_widget_mac/accelerated_widget_mac_export.h"
 #include "ui/accelerated_widget_mac/ca_renderer_layer_tree.h"
 #include "ui/gfx/ca_layer_result.h"
@@ -14,7 +15,9 @@
 #include "ui/gl/gl_surface.h"
 #include "ui/gl/presenter.h"
 
+#if !IS_MAS_BUILD()
 @class CAContext;
+#endif
 @class CALayer;
 
 namespace ui {
@@ -110,7 +113,9 @@ class ACCELERATED_WIDGET_MAC_EXPORT CALa
   // both the current tree and the pending trees.
   size_t presented_ca_layer_trees_max_length_ = 2;
 
+#if !IS_MAS_BUILD()
   CAContext* __strong ca_context_;
+#endif
 
   // The root CALayer to display the current frame. This does not change
   // over the lifetime of the object.
