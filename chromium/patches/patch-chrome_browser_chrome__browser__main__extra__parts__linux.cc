$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2024-10-26 06:59:55.773033600 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -58,7 +58,7 @@ void ChromeBrowserMainExtraPartsLinux::P
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* const command_line = base::CommandLine::ForCurrentProcess();
   auto env = base::Environment::Create();
   std::string desktop_startup_id;
