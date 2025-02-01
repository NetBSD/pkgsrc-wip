$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -27,7 +27,7 @@ void ChromeBrowserMainExtraPartsOzone::P
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Lacros's `PostMainMessageLoopRun` must be called at the very end of
   // `PostMainMessageLoopRun` in
   // `ChromeBrowserMainPartsLacros::PostMainMessageLoopRun`.
