$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/platform_window/platform_window_delegate.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ ui/platform_window/platform_window_delegate.cc
@@ -63,7 +63,7 @@ gfx::Insets PlatformWindowDelegate::Calc
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
