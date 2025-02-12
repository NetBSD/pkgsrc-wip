$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/webrtc/helpers.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/webrtc/helpers.cc
@@ -40,7 +40,7 @@ void ConfigAutomaticGainControl(const Au
     apm_config.gain_controller2.enabled = false;
     return;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the Hybrid AGC setup, which combines the AGC1 input volume controller
   // and the AGC2 digital adaptive controller.
 
