$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc
@@ -145,7 +145,7 @@ CustomizeChromePageHandler::CustomizeChr
       base::BindRepeating(&CustomizeChromePageHandler::UpdateFooterSettings,
                           base::Unretained(this)));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PrefService* local_state = g_browser_process->local_state();
   if (local_state) {
     browser_pref_change_registrar_.Init(local_state);
