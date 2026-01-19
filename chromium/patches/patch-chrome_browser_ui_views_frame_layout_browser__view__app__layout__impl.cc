$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -332,7 +332,7 @@ void BrowserViewAppLayoutImpl::DoPostLay
     label.SetSubpixelRenderingEnabled(false);
     label.SetHorizontalAlignment(gfx::ALIGN_LEFT);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
     label.SetHorizontalAlignment(gfx::ALIGN_LEFT);
 #endif
