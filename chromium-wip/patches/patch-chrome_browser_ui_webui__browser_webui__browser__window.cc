$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -22,7 +22,7 @@ namespace {
 
 // Copied from chrome/browser/ui/views/frame/browser_frame.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
