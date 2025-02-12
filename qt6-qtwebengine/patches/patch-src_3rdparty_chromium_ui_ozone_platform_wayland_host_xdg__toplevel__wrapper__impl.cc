$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc
@@ -322,7 +322,7 @@ void XDGToplevelWrapperImpl::OnToplevelC
   window_states.is_activated =
       CheckIfWlArrayHasValue(states, XDG_TOPLEVEL_STATE_ACTIVATED);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (xdg_toplevel_get_version(toplevel) >=
       XDG_TOPLEVEL_STATE_TILED_LEFT_SINCE_VERSION) {
     // All four tiled states have the same since version, so it is enough to
