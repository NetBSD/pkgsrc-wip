$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/wayland/emulate/wayland_input_emulate.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/emulate/wayland_input_emulate.h
@@ -61,7 +61,7 @@ class WaylandInputEmulate : public wl::W
                     int touch_id,
                     uint32_t request_id);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ForceUseScreenCoordinatesOnce();
 #endif
 
