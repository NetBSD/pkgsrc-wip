$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_runner_impl.h
@@ -14,6 +14,7 @@
 #include "base/memory/raw_ptr.h"
 #include "base/memory/weak_ptr.h"
 #include "base/time/time.h"
+#include "ui/base/mojom/menu_source_type.mojom.h"
 #include "ui/views/controls/menu/menu_controller_delegate.h"
 #include "ui/views/controls/menu/menu_runner_impl_interface.h"
 #include "ui/views/views_export.h"
@@ -52,6 +53,7 @@ class VIEWS_EXPORT MenuRunnerImpl : publ
                  const gfx::Rect& bounds,
                  MenuAnchorPosition anchor,
                  int32_t run_types,
+                 ui::mojom::MenuSourceType source_type,
                  gfx::NativeView native_view_for_gestures,
                  std::optional<gfx::RoundedCornersF> corners = std::nullopt,
                  std::optional<std::string> show_menu_host_duration_histogram =
