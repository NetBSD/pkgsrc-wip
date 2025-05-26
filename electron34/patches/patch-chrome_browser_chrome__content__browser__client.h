$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/chrome_content_browser_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/chrome_content_browser_client.h
@@ -538,7 +538,7 @@ class ChromeContentBrowserClient : publi
   bool IsPluginAllowedToUseDevChannelAPIs(
       content::BrowserContext* browser_context,
       const GURL& url) override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
