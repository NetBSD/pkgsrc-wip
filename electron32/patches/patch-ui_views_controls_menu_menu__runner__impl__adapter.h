$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl_adapter.h.orig	2024-10-18 12:35:12.836225700 +0000
+++ ui/views/controls/menu/menu_runner_impl_adapter.h
@@ -43,6 +43,7 @@ class VIEWS_EXPORT MenuRunnerImplAdapter
                  const gfx::Rect& bounds,
                  MenuAnchorPosition anchor,
                  int32_t types,
+                 ui::MenuSourceType source_type,
                  gfx::NativeView native_view_for_gestures,
                  std::optional<gfx::RoundedCornersF> corners = std::nullopt,
                  std::optional<std::string> show_menu_host_duration_histogram =
