$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_runner_impl_mac.mm
@@ -46,6 +46,7 @@ void MenuRunnerImplMac::RunMenuAt(
     const gfx::Rect& bounds,
     MenuAnchorPosition anchor,
     int32_t run_types,
+    ui::mojom::MenuSourceType source_type,
     gfx::NativeView native_view_for_gestures,
     std::optional<gfx::RoundedCornersF> corners,
     std::optional<std::string> show_menu_host_duration_histogram) {
@@ -59,8 +60,8 @@ void MenuRunnerImplMac::RunMenuAt(
     }
   }
   implementation_->RunMenuAt(parent, button_controller, bounds, anchor,
-                             run_types, native_view_for_gestures, corners,
-                             show_menu_host_duration_histogram);
+                             run_types, source_type, native_view_for_gestures,
+                             corners, show_menu_host_duration_histogram);
 }
 
 void MenuRunnerImplMac::Cancel() {
