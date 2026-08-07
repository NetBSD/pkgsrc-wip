$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -593,7 +593,7 @@ float TabStyleViewsImpl::GetCurrentActiv
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabStyle::TabColors TabStyleViewsImpl::CalculateTargetColors() const {
