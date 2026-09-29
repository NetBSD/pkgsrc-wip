$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc
@@ -66,6 +66,10 @@
 #define AOM_EFLAG_CALCULATE_PSNR (1 << 3)
 #endif
 
+#ifndef AOM_EFLAG_FREEZE_INTERNAL_STATE
+#define AOM_EFLAG_FREEZE_INTERNAL_STATE (1 << 2)
+#endif
+
 #if defined(WEBRTC_ENCODER_PSNR_STATS)
 constexpr bool kEnablePsnrStats = true;
 #else
