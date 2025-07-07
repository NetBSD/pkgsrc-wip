$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/prefs/prefs_tab_helper.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/prefs/prefs_tab_helper.cc
@@ -66,7 +66,7 @@
 #include <windows.h>
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If a font name in prefs default values starts with a comma, consider it's a
 // comma-separated font list and resolve it to the first available font.
 #define PREFS_FONT_LIST 1
