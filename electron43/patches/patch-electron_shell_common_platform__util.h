$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/platform_util.h.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/common/platform_util.h
@@ -60,7 +60,7 @@ bool SetLoginItemEnabled(const std::stri
                          bool enabled);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns a desktop name (e.g. 'myapp.desktop') if available.
 // Unlike libgtkui, this does *not* use "chromium-browser.desktop" as a
 // fallback.
