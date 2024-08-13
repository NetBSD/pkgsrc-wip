$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- headless/lib/browser/headless_request_context_manager.cc.orig	2024-08-06 19:52:27.346142800 +0000
+++ headless/lib/browser/headless_request_context_manager.cc
@@ -66,7 +66,7 @@ void SetCryptKeyOnce(const base::FilePat
     return;
   done_once = true;
 
-#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)) && defined(HEADLESS_USE_PREFS)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(HEADLESS_USE_PREFS)
   // The OSCrypt keys are process bound, so if network service is out of
   // process, send it the required key if it is available.
   if (content::IsOutOfProcessNetworkService()
