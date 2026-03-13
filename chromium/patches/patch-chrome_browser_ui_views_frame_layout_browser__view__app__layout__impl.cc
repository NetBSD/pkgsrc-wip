$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -386,7 +386,7 @@ void BrowserViewAppLayoutImpl::DoPostLay
 #elif BUILDFLAG(IS_WIN)
     label.SetSubpixelRenderingEnabled(false);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
 #endif
   }
