$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2024-07-24 02:44:26.863834900 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -58,7 +58,7 @@ void ChromeBrowserMainExtraPartsLinux::P
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* const command_line = base::CommandLine::ForCurrentProcess();
   auto env = base::Environment::Create();
   std::string desktop_startup_id;
