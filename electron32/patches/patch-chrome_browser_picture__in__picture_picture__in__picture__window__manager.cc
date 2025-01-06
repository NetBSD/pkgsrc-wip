$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/picture_in_picture/picture_in_picture_window_manager.cc.orig	2024-10-18 12:34:01.837113100 +0000
+++ chrome/browser/picture_in_picture/picture_in_picture_window_manager.cc
@@ -6,6 +6,7 @@
 
 #include "base/memory/raw_ptr.h"
 #include "base/numerics/safe_conversions.h"
+#include "build/branding_buildflags.h"
 #include "chrome/browser/picture_in_picture/picture_in_picture_bounds_cache.h"
 #include "chrome/browser/picture_in_picture/picture_in_picture_occlusion_tracker.h"
 #include "chrome/browser/ui/browser_navigator_params.h"
@@ -25,7 +26,9 @@
 #include "base/metrics/histogram_functions.h"
 #include "base/numerics/checked_math.h"
 #include "base/task/sequenced_task_runner.h"
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #include "chrome/browser/picture_in_picture/auto_picture_in_picture_tab_helper.h"
+#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #include "media/base/media_switches.h"
 #include "net/base/url_util.h"
 #include "third_party/blink/public/common/features.h"
@@ -49,7 +52,7 @@ constexpr gfx::Size kMinWindowSize(240, 
 // not apply to video Picture-in-Picture windows.
 constexpr double kMaxWindowSizeRatio = 0.8;
 
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && BUILDFLAG(GOOGLE_CHROME_BRANDING)
 // Returns true if a document picture-in-picture window should be focused upon
 // opening it.
 bool ShouldFocusPictureInPictureWindow(const NavigateParams& params) {
@@ -187,7 +190,7 @@ bool PictureInPictureWindowManager::Exit
     return false;
   }
 
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // The user manually closed the pip window, so let the tab helper know in case
   // the auto-pip permission dialog was visible.
   if (auto* tab_helper = AutoPictureInPictureTabHelper::FromWebContents(
@@ -383,7 +386,7 @@ gfx::Size PictureInPictureWindowManager:
 
 // static
 void PictureInPictureWindowManager::SetWindowParams(NavigateParams& params) {
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Always show document picture-in-picture in a new window. When this is
   // not opened via the AutoPictureInPictureTabHelper, focus the window.
   params.window_action = ShouldFocusPictureInPictureWindow(params)
@@ -469,6 +472,7 @@ PictureInPictureWindowManager::GetOverla
     return nullptr;
   }
 
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // It would be nice to create this in `EnterPictureInPicture*`, but detecting
   // auto-pip while pip is in the process of opening doesn't work.
   //
@@ -507,6 +511,8 @@ PictureInPictureWindowManager::GetOverla
   }
 
   return overlay_view;
+#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
+  return nullptr;
 }
 
 PictureInPictureOcclusionTracker*
