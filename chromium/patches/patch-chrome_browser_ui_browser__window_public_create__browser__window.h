$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_window/public/create_browser_window.h.orig	2026-09-07 10:14:27.000000000 +0000
+++ chrome/browser/ui/browser_window/public/create_browser_window.h
@@ -181,7 +181,7 @@ struct BrowserWindowCreateParams {
   std::optional<int64_t> display_id;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // When the browser window is shown, the desktop environment is notified
   // using this ID. In response, the desktop will stop playing the "waiting
   // for startup" animation (if any).
