$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/extension_status_utils.h.orig	2024-08-21 22:46:11.710749400 +0000
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -55,7 +55,7 @@ bool IsExternalExtensionUninstalled(cont
 bool ClearExternalExtensionUninstalled(content::BrowserContext* context,
                                        const std::string& extension_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this method returns true, then |extension_id| will not be launchable.
 //
 // The eventual goal is that this method should return true for all hosted apps,
