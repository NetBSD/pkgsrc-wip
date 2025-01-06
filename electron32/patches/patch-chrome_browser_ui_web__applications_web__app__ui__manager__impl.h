$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2024-10-18 12:34:03.608132800 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -222,7 +222,7 @@ class WebAppUiManagerImpl : public Brows
       UninstallCompleteCallback uninstall_complete_callback,
       webapps::UninstallResultCode uninstall_code);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(const Browser* browser,
                                                    const webapps::AppId& app_id,
                                                    bool is_activated);
