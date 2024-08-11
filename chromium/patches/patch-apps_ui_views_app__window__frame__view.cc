$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- apps/ui/views/app_window_frame_view.cc.orig	2024-07-24 02:44:21.071273800 +0000
+++ apps/ui/views/app_window_frame_view.cc
@@ -148,7 +148,7 @@ gfx::Rect AppWindowFrameView::GetWindowB
   gfx::Rect window_bounds = client_bounds;
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
