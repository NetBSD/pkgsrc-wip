$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_controller.h.orig	2024-10-18 12:35:12.832227200 +0000
+++ ui/views/controls/menu/menu_controller.h
@@ -137,6 +137,7 @@ class VIEWS_EXPORT MenuController final 
            MenuAnchorPosition position,
            bool context_menu,
            bool is_nested_drag,
+           ui::MenuSourceType source_type,
            gfx::NativeView native_view_for_gestures = gfx::NativeView());
 
   bool for_drop() const { return for_drop_; }
