$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2024-11-14 01:04:04.881566800 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -227,7 +227,7 @@ class WebAppUiManagerImpl : public Brows
       UninstallCompleteCallback uninstall_complete_callback,
       webapps::UninstallResultCode uninstall_code);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(const Browser* browser,
                                                    const webapps::AppId& app_id,
                                                    bool is_activated);
