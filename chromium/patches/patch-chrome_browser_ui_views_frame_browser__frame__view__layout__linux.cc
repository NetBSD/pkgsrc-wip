$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2024-12-03 23:30:11.643021300 +0000
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -54,7 +54,7 @@ gfx::Insets BrowserFrameViewLayoutLinux:
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
