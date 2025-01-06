$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/platform_window/platform_window_delegate.cc.orig	2024-10-18 12:35:12.780248000 +0000
+++ ui/platform_window/platform_window_delegate.cc
@@ -61,7 +61,7 @@ gfx::Insets PlatformWindowDelegate::Calc
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
