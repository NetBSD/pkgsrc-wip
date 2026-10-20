$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/common/electron_paths.h.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/shell/common/electron_paths.h
@@ -31,7 +31,7 @@ enum {
   DIR_RECENT,  // Directory where recent files live
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
