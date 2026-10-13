$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/font_util.cc.orig	2026-10-13 15:23:13.892834818 +0000
+++ ui/gfx/font_util.cc
@@ -26,8 +26,11 @@ void InitializeFonts() {
   // the long delay the user would have seen on first rendering.
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
-  // Early initialize FontConfig.
-  InitializeGlobalFontConfigAsync();
+  // Ensures the config is created on this thread. It's generally safe to send
+  // concurrent match requests to fontconfig, but it's unsafe to send match
+  // requests concurrently to fontconfig initialization.
+  FcConfig* config = GetGlobalFontConfig();
+  DCHECK(config);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN)
