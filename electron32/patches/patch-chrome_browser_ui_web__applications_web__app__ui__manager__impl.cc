$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2024-10-18 12:34:03.608132800 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -577,7 +577,7 @@ void WebAppUiManagerImpl::MaybeShowIPHPr
     content::WebContents* web_contents,
     Profile* profile,
     const std::string& app_id) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForWebApps(profile);
   CHECK(provider);
 
@@ -797,7 +797,7 @@ void WebAppUiManagerImpl::ClearWebAppSit
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebAppUiManagerImpl::ShowIPHPromoForAppsLaunchedViaLinkCapturing(
     const Browser* browser,
     const webapps::AppId& app_id,
