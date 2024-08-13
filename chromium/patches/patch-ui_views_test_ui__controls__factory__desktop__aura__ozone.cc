$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2024-08-06 19:52:57.904725300 +0000
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -296,7 +296,7 @@ void UpdateDisplaySync(const std::string
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
