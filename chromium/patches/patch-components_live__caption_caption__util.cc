$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/live_caption/caption_util.cc.orig	2024-07-24 02:44:34.216547000 +0000
+++ components/live_caption/caption_util.cc
@@ -144,7 +144,7 @@ std::string GetCaptionSettingsUrl() {
   return "chrome://os-settings/audioAndCaptions";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #endif  // BUILDFLAG(IS_LINUX)
 
