$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/platform_util.h.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/common/platform_util.h
@@ -56,7 +56,7 @@ bool SetLoginItemEnabled(const std::stri
                          bool enabled);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns a success flag.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 bool GetDesktopName(std::string* setme);
