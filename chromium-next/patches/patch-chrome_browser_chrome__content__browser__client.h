$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_content_browser_client.h.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/chrome_content_browser_client.h
@@ -550,7 +550,7 @@ class ChromeContentBrowserClient : publi
   bool IsPluginAllowedToUseDevChannelAPIs(
       content::BrowserContext* browser_context,
       const GURL& url) override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
