$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/test/fake_display_client.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/viz/test/fake_display_client.cc
@@ -27,7 +27,7 @@ void FakeDisplayClient::AddChildWindowTo
     gpu::SurfaceHandle child_window) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void FakeDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {}
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
