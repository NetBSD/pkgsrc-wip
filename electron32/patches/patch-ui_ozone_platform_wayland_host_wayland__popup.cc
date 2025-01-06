$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/wayland_popup.cc.orig	2024-10-18 12:35:12.760256000 +0000
+++ ui/ozone/platform/wayland/host/wayland_popup.cc
@@ -34,7 +34,7 @@ WaylandPopup::WaylandPopup(PlatformWindo
                            WaylandWindow* parent)
     : WaylandWindow(delegate, connection) {
   set_parent_window(parent);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/330384470): Whether the popup appear depends on whether
   // anchor point is outside of the parent xdg_surface. On Mutter the popup will
   // not show when outside.
