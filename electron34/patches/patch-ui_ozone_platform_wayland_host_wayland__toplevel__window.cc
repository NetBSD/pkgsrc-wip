$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/wayland_toplevel_window.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.cc
@@ -616,7 +616,7 @@ void WaylandToplevelWindow::HandleToplev
   bool prev_suspended = is_suspended_;
   is_suspended_ = window_states.is_suspended;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The tiled state affects the window geometry, so apply it here.
   if (window_states.tiled_edges != tiled_state_) {
     // This configure changes the decoration insets.  We should adjust the
