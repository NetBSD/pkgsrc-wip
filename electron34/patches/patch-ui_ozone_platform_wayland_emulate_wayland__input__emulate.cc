$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc
@@ -284,7 +284,7 @@ void WaylandInputEmulate::EmulateUpdateD
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandInputEmulate::ForceUseScreenCoordinatesOnce() {
   force_use_screen_coordinates_once_ = true;
 }
