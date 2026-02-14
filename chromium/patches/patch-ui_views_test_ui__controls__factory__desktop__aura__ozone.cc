$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -237,7 +237,7 @@ bool SendMouseClick(MouseButton type, gf
                          window_hint);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
