$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2024-10-26 07:00:00.957183100 +0000
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -61,7 +61,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_paint_utils_linux.h"
@@ -93,7 +93,7 @@ constexpr int kContentSettingIconSize = 
 // The height of the controls bar at the top of the window.
 constexpr int kTopControlsHeight = 34;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Frame border when window shadow is not drawn.
 constexpr int kFrameBorderThickness = 4;
 #endif
@@ -188,7 +188,7 @@ class WindowEventObserver : public ui::E
 
     gfx::Rect input_bounds = pip_browser_frame_view_->GetLocalBounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Calculate input bounds for Linux. This is needed because the input bounds
     // is not necessary the same as the local bounds on Linux.
     if (pip_browser_frame_view_->ShouldDrawFrameShadow()) {
@@ -591,7 +591,7 @@ PictureInPictureBrowserFrameView::Pictur
         AddChildView(std::move(auto_pip_setting_overlay));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile = browser_view->browser()->profile();
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -813,7 +813,7 @@ void PictureInPictureBrowserFrameView::O
   for (ContentSettingImageView* view : content_setting_views_)
     view->SetIconColor(color_provider->GetColor(kColorPipWindowForeground));
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // On Linux the top bar background will be drawn in OnPaint().
   top_bar_container_view_->SetBackground(views::CreateSolidBackground(
       color_provider->GetColor(kColorPipWindowTopBarBackground)));
@@ -897,7 +897,7 @@ void PictureInPictureBrowserFrameView::R
   BrowserNonClientFrameView::RemovedFromWidget();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::Insets
 PictureInPictureBrowserFrameView::RestoredMirroredFrameBorderInsets() const {
   auto border = FrameBorderInsets();
@@ -1189,7 +1189,7 @@ void PictureInPictureBrowserFrameView::A
 // views::View implementations:
 
 void PictureInPictureBrowserFrameView::OnPaint(gfx::Canvas* canvas) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Draw the PiP window frame borders and shadows, including the top bar
   // background.
   if (window_frame_provider_) {
@@ -1344,7 +1344,7 @@ void PictureInPictureBrowserFrameView::U
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::FrameBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     const auto insets = window_frame_provider_->GetFrameThicknessDip();
     const bool tiled = frame()->tiled();
@@ -1362,7 +1362,7 @@ gfx::Insets PictureInPictureBrowserFrame
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::ResizeBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderInsets();
 #elif !BUILDFLAG(IS_CHROMEOS_ASH)
   return gfx::Insets(kResizeBorder);
@@ -1383,7 +1383,7 @@ gfx::Size PictureInPictureBrowserFrameVi
                    top_height + border_thickness.bottom());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool PictureInPictureBrowserFrameView::ShouldDrawFrameShadow() const {
   return static_cast<DesktopBrowserFrameAuraLinux*>(
              frame()->native_browser_frame())
