$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/overlay/video_overlay_window_views.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/views/overlay/video_overlay_window_views.cc
@@ -17,9 +17,11 @@
 #include "build/build_config.h"
 #include "chrome/browser/picture_in_picture/picture_in_picture_occlusion_tracker.h"
 #include "chrome/browser/picture_in_picture/picture_in_picture_window_manager.h"
+#if 0
 #include "chrome/browser/profiles/profile.h"
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
+#endif
 #include "chrome/browser/ui/color/chrome_color_id.h"
 #include "chrome/browser/ui/views/overlay/back_to_tab_button.h"
 #include "chrome/browser/ui/views/overlay/back_to_tab_label_button.h"
@@ -63,7 +65,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_WIN)
+#if 0
 #include "chrome/browser/shell_integration_win.h"
 #include "content/public/browser/render_widget_host_view.h"
 #include "ui/aura/window.h"
@@ -323,7 +325,7 @@ std::unique_ptr<VideoOverlayWindowViews>
   overlay_window->Init(std::move(params));
   overlay_window->OnRootViewReady();
 
-#if BUILDFLAG(IS_WIN)
+#if 0
   std::wstring app_user_model_id;
   Browser* browser = chrome::FindBrowserWithTab(controller->GetWebContents());
   if (browser) {
@@ -356,11 +358,13 @@ std::unique_ptr<VideoOverlayWindowViews>
 
 #endif  // BUILDFLAG(IS_WIN)
 
+#if 0
   PictureInPictureOcclusionTracker* tracker =
       PictureInPictureWindowManager::GetInstance()->GetOcclusionTracker();
   if (tracker) {
     tracker->OnPictureInPictureWidgetOpened(overlay_window.get());
   }
+#endif
 
   return overlay_window;
 }
