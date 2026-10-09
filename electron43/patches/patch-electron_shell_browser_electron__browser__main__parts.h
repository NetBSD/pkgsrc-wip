$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/electron_browser_main_parts.h.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -144,7 +144,7 @@ class ElectronBrowserMainParts : public 
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void JoinSystemFontConfigInit();
 
   base::PlatformThreadHandle system_fontconfig_thread_;
