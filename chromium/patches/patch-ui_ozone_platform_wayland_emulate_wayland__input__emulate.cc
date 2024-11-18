$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc.orig	2024-11-14 01:04:23.958757400 +0000
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc
@@ -284,7 +284,7 @@ void WaylandInputEmulate::EmulateUpdateD
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandInputEmulate::ForceUseScreenCoordinatesOnce() {
   force_use_screen_coordinates_once_ = true;
 }
