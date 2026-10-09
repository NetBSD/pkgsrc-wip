$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_base_window.h.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -265,7 +265,7 @@ class BaseWindow : public gin_helper::Tr
   v8::Local<v8::Value> GetAccentColor() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin::Arguments* args);
 #endif
