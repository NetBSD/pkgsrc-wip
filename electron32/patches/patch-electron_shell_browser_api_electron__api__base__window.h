$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_base_window.h.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -241,7 +241,7 @@ class BaseWindow : public gin_helper::Tr
   void SetAppDetails(const gin_helper::Dictionary& options);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin_helper::Arguments* args);
 #endif
