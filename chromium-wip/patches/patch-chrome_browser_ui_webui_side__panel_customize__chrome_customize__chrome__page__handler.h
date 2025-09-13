$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h
@@ -206,7 +206,7 @@ class CustomizeChromePageHandler
   // value needs to be requeried by the page.
   GURL last_source_url_{GURL(chrome::kChromeUINewTabPageURL)};
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PrefChangeRegistrar browser_pref_change_registrar_;
 #endif
   PrefChangeRegistrar pref_change_registrar_;
