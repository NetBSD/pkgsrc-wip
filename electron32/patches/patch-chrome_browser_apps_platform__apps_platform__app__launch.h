$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/apps/platform_apps/platform_app_launch.h.orig	2024-10-18 12:34:01.009575000 +0000
+++ chrome/browser/apps/platform_apps/platform_app_launch.h
@@ -38,7 +38,7 @@ bool OpenExtensionApplicationWindow(Prof
 content::WebContents* OpenExtensionApplicationTab(Profile* profile,
                                                   const std::string& app_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Opens the deprecated Chrome Apps flow if |app_id| refers to a Chrome App and
 // Chrome Apps are deprecated on the |profile|. Returns true if that was the
 // case, or false otherwise.
