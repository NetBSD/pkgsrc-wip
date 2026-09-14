$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc.orig	2026-09-07 10:14:27.000000000 +0000
+++ chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc
@@ -256,7 +256,7 @@ int BrowserViewTabbedLayoutImpl::GetHori
 }
 
 int BrowserViewTabbedLayoutImpl::GetVerticalTabStripContentOverlap() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // On fractional display scaling (e.g. 1.25x, 1.5x), overlap the content area
   // by 1 DIP over the vertical tab strip border to prevent subpixel seams.
   if (auto* const widget = views().browser_view->GetWidget()) {
