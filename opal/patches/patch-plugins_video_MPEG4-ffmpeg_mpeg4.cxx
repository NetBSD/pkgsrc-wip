$NetBSD: patch-plugins_video_MPEG4-ffmpeg_mpeg4.cxx,v 1.1 2011/12/04 22:06:04 marino Exp $

--- plugins/video/MPEG4-ffmpeg/mpeg4.cxx.orig	2013-02-20 02:18:07.000000000 +0000
+++ plugins/video/MPEG4-ffmpeg/mpeg4.cxx
@@ -103,6 +103,7 @@ extern "C" {
 
 #else /* LIBAVCODEC_HAVE_SOURCE_DIR */
 #include "../common/ffmpeg.h"
+#include <libavutil/opt.h>
 #endif /* LIBAVCODEC_HAVE_SOURCE_DIR */
 }
 
@@ -205,7 +206,7 @@ const static struct mpeg4_resolution {
     { 0 }
 };
 
-FFMPEGLibrary FFMPEGLibraryInstance(CODEC_ID_MPEG4);
+FFMPEGLibrary FFMPEGLibraryInstance(AV_CODEC_ID_MPEG4);
 
 
 static bool mpeg4IsIframe (BYTE * frameBuffer, unsigned int frameLen )
@@ -539,7 +540,7 @@ void MPEG4EncoderContext::ResetBitCounte
 //
 
 void MPEG4EncoderContext::SetStaticEncodingParams(){
-    m_avcontext->pix_fmt = PIX_FMT_YUV420P;
+    m_avcontext->pix_fmt = AV_PIX_FMT_YUV420P;
     m_avcontext->mb_decision = FF_MB_DECISION_SIMPLE;    // high quality off
     m_avcontext->rtp_payload_size = 750;                 // ffh263 uses 750
     m_avcontext->rtp_callback = &MPEG4EncoderContext::RtpCallback;
@@ -589,17 +590,16 @@ void MPEG4EncoderContext::SetStaticEncod
     m_avpicture->quality = m_videoQMin;
 
 #ifdef USE_ORIG
-    m_avcontext->flags |= CODEC_FLAG_PART;   // data partitioning
+    av_opt_set_int(m_avcontext->priv_data, "data_partitionin", 1, 0);
     m_avcontext->flags |= CODEC_FLAG_4MV;    // 4 motion vectors
 #else
     m_avcontext->max_b_frames=0; /*don't use b frames*/
     m_avcontext->flags|=CODEC_FLAG_AC_PRED;
-    m_avcontext->flags|=CODEC_FLAG_H263P_UMV;
+    av_opt_set_int(m_avcontext->priv_data, "umv", 1, 0);
     /*c->flags|=CODEC_FLAG_QPEL;*/ /*don't enable this one: this forces profile_level to advanced simple profile */
     m_avcontext->flags|=CODEC_FLAG_4MV;
-    m_avcontext->flags|=CODEC_FLAG_GMC;
     m_avcontext->flags|=CODEC_FLAG_LOOP_FILTER;
-    m_avcontext->flags|=CODEC_FLAG_H263P_SLICE_STRUCT;
+    av_opt_set_int(m_avcontext->priv_data, "structured_slices", 1, 0);
 #endif
     m_avcontext->opaque = this;              // for use in RTP callback
 }
@@ -703,7 +703,7 @@ bool MPEG4EncoderContext::OpenCodec()
     return false;
   }
 
-  if((m_avcodec = FFMPEGLibraryInstance.AvcodecFindEncoder(CODEC_ID_MPEG4)) == NULL){
+  if((m_avcodec = FFMPEGLibraryInstance.AvcodecFindEncoder(AV_CODEC_ID_MPEG4)) == NULL){
     PTRACE(1, "MPEG4", "Encoder not found");
     return false;
   }
@@ -713,13 +713,14 @@ bool MPEG4EncoderContext::OpenCodec()
   if (PTRACE_CHECK(4)) {
     m_avcontext->debug |= FF_DEBUG_RC;
     m_avcontext->debug |= FF_DEBUG_PICT_INFO;
-    m_avcontext->debug |= FF_DEBUG_MV;
   }
 #endif
   
   SetStaticEncodingParams();
   SetDynamicEncodingParams(false);    // don't force a restart, it's not open
-  if (FFMPEGLibraryInstance.AvcodecOpen(m_avcontext, m_avcodec) < 0)
+  AVDictionary *opts = NULL;
+  av_dict_set_int(&opts, "gmc", 1, 0);
+  if (FFMPEGLibraryInstance.AvcodecOpen(m_avcontext, m_avcodec, &opts) < 0)
   {
     PTRACE(1, "MPEG4", "Encoder could not be opened");
     return false;
@@ -804,7 +805,7 @@ int MPEG4EncoderContext::EncodeFrames(co
         // Should the next frame be an I-Frame?
         if ((flags & PluginCodec_CoderForceIFrame) || (m_frameNum == 0))
         {
-            m_avpicture->pict_type = FF_I_TYPE;
+            m_avpicture->pict_type = AV_PICTURE_TYPE_I;
         }
         else // No IFrame requested, let avcodec decide what to do
         {
@@ -1325,7 +1326,7 @@ void MPEG4DecoderContext::SetFrameHeight
 
 void MPEG4DecoderContext::SetStaticDecodingParams() {
     m_avcontext->flags |= CODEC_FLAG_4MV; 
-    m_avcontext->flags |= CODEC_FLAG_PART;
+    av_opt_set_int(m_avcontext->priv_data, "data_partitionin", 1, 0);
     m_avcontext->workaround_bugs = 0; // no workaround for buggy implementations
 }
 
@@ -1394,7 +1395,7 @@ void MPEG4DecoderContext::ResizeDecoding
 
 bool MPEG4DecoderContext::OpenCodec()
 {
-    if ((m_avcodec = FFMPEGLibraryInstance.AvcodecFindDecoder(CODEC_ID_MPEG4)) == NULL) {
+    if ((m_avcodec = FFMPEGLibraryInstance.AvcodecFindDecoder(AV_CODEC_ID_MPEG4)) == NULL) {
         PTRACE(1, "MPEG4", "Decoder not found for encoder");
         return false;
     }
@@ -1415,7 +1416,7 @@ bool MPEG4DecoderContext::OpenCodec()
 
     SetStaticDecodingParams();
     SetDynamicDecodingParams(false);    // don't force a restart, it's not open
-    if (FFMPEGLibraryInstance.AvcodecOpen(m_avcontext, m_avcodec) < 0) {
+    if (FFMPEGLibraryInstance.AvcodecOpen(m_avcontext, m_avcodec, NULL) < 0) {
         PTRACE(1, "MPEG4", "Decoder failed to open");
         return false;
     }
