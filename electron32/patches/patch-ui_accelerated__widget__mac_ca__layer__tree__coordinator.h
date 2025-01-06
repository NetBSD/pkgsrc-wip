$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accelerated_widget_mac/ca_layer_tree_coordinator.h.orig	2024-10-18 12:35:11.560735000 +0000
+++ ui/accelerated_widget_mac/ca_layer_tree_coordinator.h
@@ -14,7 +14,9 @@
 #include "ui/gl/gl_surface.h"
 #include "ui/gl/presenter.h"
 
+#if !IS_MAS_BUILD()
 @class CAContext;
+#endif
 @class CALayer;
 
 namespace ui {
@@ -110,7 +112,9 @@ class ACCELERATED_WIDGET_MAC_EXPORT CALa
   // both the current tree and the pending trees.
   size_t presented_ca_layer_trees_max_length_ = 2;
 
+#if !IS_MAS_BUILD()
   CAContext* __strong ca_context_;
+#endif
 
   // The root CALayer to display the current frame. This does not change
   // over the lifetime of the object.
