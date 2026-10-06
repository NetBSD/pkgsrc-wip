$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl_interface.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_runner_impl_interface.h
@@ -9,6 +9,7 @@
 #include <string>
 
 #include "base/functional/callback_forward.h"
+#include "ui/base/mojom/menu_source_type.mojom.h"
 #include "ui/views/controls/menu/menu_runner.h"
 
 namespace gfx {
@@ -46,6 +47,7 @@ class MenuRunnerImplInterface {
       const gfx::Rect& bounds,
       MenuAnchorPosition anchor,
       int32_t run_types,
+      ui::mojom::MenuSourceType source_type,
       gfx::NativeView native_view_for_gestures,
       std::optional<gfx::RoundedCornersF> corners = std::nullopt,
       std::optional<std::string> show_menu_host_duration_histogram =
