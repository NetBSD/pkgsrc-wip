$NetBSD: patch-chrome_browser_ui_views_frame_picture__in__picture__browser__frame__view.h,v 1.1 2025/02/06 09:57:54 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -27,7 +27,7 @@
 #include "ui/views/layout/flex_layout_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -35,7 +35,7 @@
 // parent window, so to prevent cutting off important dialogs we resize the
 // picture-in-picture window to fit them. While ChromeOS Ash also uses Aura, it
 // does not have this issue so we do not resize on ChromeOS Ash.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define RESIZE_DOCUMENT_PICTURE_IN_PICTURE_TO_DIALOG 1
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)
@@ -103,7 +103,7 @@ class PictureInPictureBrowserFrameView
   void Layout(PassKey) override;
   void AddedToWidget() override;
   void RemovedFromWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets RestoredMirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -195,7 +195,7 @@ class PictureInPictureBrowserFrameView
   // Returns true if there's an overlay view that's currently shown.
   bool IsOverlayViewVisible() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether a client-side shadow should be drawn for the window.
   bool ShouldDrawFrameShadow() const;
 
@@ -376,7 +376,7 @@ class PictureInPictureBrowserFrameView
   // `top_bar_color_animation_`.
   std::optional<SkColor> current_foreground_color_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
