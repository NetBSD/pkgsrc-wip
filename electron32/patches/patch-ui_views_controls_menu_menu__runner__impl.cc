$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl.cc.orig	2024-10-18 12:35:12.832227200 +0000
+++ ui/views/controls/menu/menu_runner_impl.cc
@@ -115,6 +115,7 @@ void MenuRunnerImpl::RunMenuAt(
     const gfx::Rect& bounds,
     MenuAnchorPosition anchor,
     int32_t run_types,
+    ui::MenuSourceType source_type,
     gfx::NativeView native_view_for_gestures,
     std::optional<gfx::RoundedCornersF> corners,
     std::optional<std::string> show_menu_host_duration_histogram) {
@@ -189,7 +190,7 @@ void MenuRunnerImpl::RunMenuAt(
   controller->Run(parent, button_controller, menu_.get(), bounds, anchor,
                   (run_types & MenuRunner::CONTEXT_MENU) != 0,
                   (run_types & MenuRunner::NESTED_DRAG) != 0,
-                  native_view_for_gestures);
+                  source_type, native_view_for_gestures);
 }
 
 void MenuRunnerImpl::Cancel() {
