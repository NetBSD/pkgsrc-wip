$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2026-09-17 03:47:47.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -271,7 +271,7 @@ class WebAppUiManagerImpl : public Brows
       webapps::UninstallResultCode uninstall_code);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(
       BrowserWindowInterface* browser,
       const webapps::AppId& app_id,
