$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/sessions/session_restore.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/sessions/session_restore.cc
@@ -102,7 +102,7 @@
 #include "chrome/browser/web_applications/web_app_registrar.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_fetcher.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1138,7 +1138,7 @@ class SessionRestoreImpl : public Browse
     bool is_first_tab = true;
     for (const auto& startup_tab : startup_tabs) {
       const GURL& url = startup_tab.url;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (url == whats_new::GetWebUIStartupURL()) {
         whats_new::StartWhatsNewFetch(browser);
         continue;
