$NetBSD$

--- plugins/video/H.264/h264-x264.cxx.orig	2013-02-20 02:18:02.000000000 +0000
+++ plugins/video/H.264/h264-x264.cxx
@@ -41,4 +41,7 @@
 #endif
 
+#define FF_IDCT_H264 11
+#define CODEC_FLAG2_SKIP_RD 0x00004000
+
 #include <codec/opalplugin.hpp>
 
@@ -105,5 +108,5 @@ static struct PluginCodec_information Li
 ///////////////////////////////////////////////////////////////////////////////
 
-FFMPEGLibrary FFMPEGLibraryInstance(CODEC_ID_H264);
+FFMPEGLibrary FFMPEGLibraryInstance(AV_CODEC_ID_H264);
 
 PLUGINCODEC_CONTROL_LOG_FUNCTION_DEF
@@ -1065,5 +1068,5 @@ class MyDecoder : public PluginCodec<MY_
          be done in the normal C++ constructor. */
 
-      if ((m_codec = FFMPEGLibraryInstance.AvcodecFindDecoder(CODEC_ID_H264)) == NULL)
+      if ((m_codec = FFMPEGLibraryInstance.AvcodecFindDecoder(AV_CODEC_ID_H264)) == NULL)
         return false;
 
@@ -1072,11 +1075,7 @@ class MyDecoder : public PluginCodec<MY_
 
       m_context->workaround_bugs = FF_BUG_AUTODETECT;
-      m_context->error_recognition = FF_ER_AGGRESSIVE;
       m_context->idct_algo = FF_IDCT_H264;
       m_context->error_concealment = FF_EC_GUESS_MVS | FF_EC_DEBLOCK;
-      m_context->flags = CODEC_FLAG_INPUT_PRESERVED | CODEC_FLAG_EMU_EDGE;
-      m_context->flags2 = CODEC_FLAG2_BRDO |
-                          CODEC_FLAG2_MEMC_ONLY |
-                          CODEC_FLAG2_DROP_FRAME_TIMECODE |
+      m_context->flags2 = CODEC_FLAG2_DROP_FRAME_TIMECODE |
                           CODEC_FLAG2_SKIP_RD |
                           CODEC_FLAG2_CHUNKS;
@@ -1085,5 +1084,5 @@ class MyDecoder : public PluginCodec<MY_
         return false;
 
-      if (FFMPEGLibraryInstance.AvcodecOpen(m_context, m_codec) < 0)
+      if (FFMPEGLibraryInstance.AvcodecOpen(m_context, m_codec, NULL) < 0)
         return false;
 
