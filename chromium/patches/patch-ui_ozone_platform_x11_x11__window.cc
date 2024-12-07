$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/x11_window.cc.orig	2024-12-03 23:30:51.893620300 +0000
+++ ui/ozone/platform/x11/x11_window.cc
@@ -1504,7 +1504,7 @@ void X11Window::OnXWindowStateChanged() 
   WindowTiledEdges tiled_state = GetTiledState();
   if (tiled_state != tiled_state_) {
     tiled_state_ = tiled_state;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     platform_window_delegate_->OnWindowTiledStateChanged(tiled_state);
     UpdateDecorationInsets();
 #endif
