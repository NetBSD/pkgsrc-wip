$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl_adapter.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_runner_impl_adapter.cc
@@ -35,11 +35,12 @@ void MenuRunnerImplAdapter::RunMenuAt(
     const gfx::Rect& bounds,
     MenuAnchorPosition anchor,
     int32_t types,
+    ui::mojom::MenuSourceType source_type,
     gfx::NativeView native_view_for_gestures,
     std::optional<gfx::RoundedCornersF> corners,
     std::optional<std::string> show_menu_host_duration_histogram) {
   impl_->RunMenuAt(parent, button_controller, bounds, anchor, types,
-                   native_view_for_gestures);
+                   source_type, native_view_for_gestures);
 }
 
 void MenuRunnerImplAdapter::Cancel() {
