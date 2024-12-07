$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2024-12-03 23:30:11.795035000 +0000
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -550,7 +550,7 @@ float TabStyleViewsImpl::GetCurrentActiv
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
