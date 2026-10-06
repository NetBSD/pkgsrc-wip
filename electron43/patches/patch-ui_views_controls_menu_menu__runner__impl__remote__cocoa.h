$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl_remote_cocoa.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_runner_impl_remote_cocoa.h
@@ -15,6 +15,7 @@
 #include "components/remote_cocoa/common/menu.mojom.h"
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "mojo/public/cpp/bindings/receiver_set.h"
+#include "ui/base/mojom/menu_source_type.mojom.h"
 #include "ui/views/controls/menu/menu_runner_impl_interface.h"
 
 namespace views {
@@ -57,6 +58,7 @@ class VIEWS_EXPORT MenuRunnerImplRemoteC
       const gfx::Rect& bounds,
       MenuAnchorPosition anchor,
       int32_t run_types,
+      ui::mojom::MenuSourceType source_type,
       gfx::NativeView native_view_for_gestures,
       std::optional<gfx::RoundedCornersF> corners,
       std::optional<std::string> show_menu_host_duration_histogram) override;
