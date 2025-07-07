$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -28,7 +28,7 @@ void ChromeBrowserMainExtraPartsOzone::P
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
