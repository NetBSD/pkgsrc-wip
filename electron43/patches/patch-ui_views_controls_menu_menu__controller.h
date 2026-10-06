$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_controller.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_controller.h
@@ -138,6 +138,7 @@ class VIEWS_EXPORT MenuController final 
            MenuAnchorPosition position,
            bool context_menu,
            bool is_nested_drag,
+           ui::mojom::MenuSourceType source_type,
            gfx::NativeView native_view_for_gestures = gfx::NativeView());
 
   bool for_drop() const { return for_drop_; }
