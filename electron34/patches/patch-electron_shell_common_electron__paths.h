$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/electron_paths.h.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/common/electron_paths.h
@@ -30,7 +30,7 @@ enum {
   DIR_RECENT,  // Directory where recent files live
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
