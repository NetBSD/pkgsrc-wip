$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc
@@ -299,7 +299,9 @@ int LibaomAv1Encoder::InitEncode(const V
     SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_ENABLE_PALETTE, 0);
   }
 
+#ifdef notyet
   SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_AUTO_TILES, 1);
+#endif
   SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_ROW_MT, 1);
   SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_ENABLE_OBMC, 0);
   SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_NOISE_SENSITIVITY, 0);
@@ -332,8 +334,10 @@ int LibaomAv1Encoder::InitEncode(const V
   SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_MAX_REFERENCE_FRAMES, 3);
 
   if (adaptive_max_consec_drops_) {
+#ifdef notyet
     SET_ENCODER_PARAM_OR_RETURN_ERROR(AV1E_SET_MAX_CONSEC_FRAME_DROP_MS_CBR,
                                       250);
+#endif
   }
 
   return WEBRTC_VIDEO_CODEC_OK;
