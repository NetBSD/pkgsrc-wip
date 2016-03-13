$NetBSD: patch-plugins_video_H.263-1998_h263-1993.cxx,v 1.2 2013/01/19 20:29:24 riastradh Exp $

--- plugins/video/H.263-1998/h263-1998.cxx.orig	2013-02-20 02:18:03.000000000 +0000
+++ plugins/video/H.263-1998/h263-1998.cxx
@@ -48,6 +48,10 @@
 #endif
 
 #include "h263-1998.h"
+extern "C"
+{
+#include <libavutil/opt.h>
+}
 #include <limits>
 #include <iomanip>
 #include <stdio.h>
@@ -94,7 +98,7 @@ static struct StdSizes {
   { CIF16_WIDTH, CIF16_HEIGHT, PLUGINCODEC_CIF16_MPI },
 };
 
-static FFMPEGLibrary FFMPEGLibraryInstance(CODEC_ID_H263P);
+static FFMPEGLibrary FFMPEGLibraryInstance(AV_CODEC_ID_H263P);
 
 
 /////////////////////////////////////////////////////////////////////////////
@@ -203,7 +207,7 @@ H263_Base_EncoderContext::~H263_Base_Enc
   PTRACE(4, m_prefix, "Encoder closed");
 }
 
-bool H263_Base_EncoderContext::Init(CodecID codecId)
+bool H263_Base_EncoderContext::Init(AVCodecID codecId)
 {
   PTRACE(5, m_prefix, "Opening encoder");
 
@@ -230,11 +234,10 @@ bool H263_Base_EncoderContext::Init(Code
 
   m_context->opaque = this;
 
-  m_context->flags = CODEC_FLAG_EMU_EDGE   // don't draw edges
-                   | CODEC_FLAG_TRUNCATED  // Possible missing packets
+  m_context->flags = CODEC_FLAG_TRUNCATED  // Possible missing packets
                    ;
 
-  m_context->pix_fmt = PIX_FMT_YUV420P;
+  m_context->pix_fmt = AV_PIX_FMT_YUV420P;
   m_context->gop_size = H263_KEY_FRAME_INTERVAL;
 
   // X-Lite does not like Custom Picture frequency clocks... stick to 29.97Hz
@@ -317,9 +320,9 @@ void H263_Base_EncoderContext::SetOption
     // Level 2+ 
     // works with eyeBeam, signaled via  non-standard "D"
     if (atoi(value) == 1)
-      m_context->flags |= CODEC_FLAG_H263P_UMV; 
+      av_opt_set_int(m_context->priv_data, "umv", 1, 0);
     else
-      m_context->flags &= ~CODEC_FLAG_H263P_UMV; 
+      av_opt_set_int(m_context->priv_data, "umv", 0, 0);
     return;
   }
 
@@ -328,9 +331,9 @@ void H263_Base_EncoderContext::SetOption
     // Annex F: Advanced Prediction Mode
     // does not work with eyeBeam
     if (atoi(value) == 1)
-      m_context->flags |= CODEC_FLAG_OBMC; 
+      av_opt_set_int(m_context->priv_data, "obmc", 1, 0);
     else
-      m_context->flags &= ~CODEC_FLAG_OBMC; 
+      av_opt_set_int(m_context->priv_data, "obmc", 0, 0);
     return;
   }
 #endif
@@ -340,9 +343,9 @@ void H263_Base_EncoderContext::SetOption
     // Level 3+
     // works with eyeBeam
     if (atoi(value) == 1)
-      m_context->flags |= CODEC_FLAG_AC_PRED; 
+      av_opt_set_int(m_context->priv_data, "structured_slices", 1, 0);
     else
-      m_context->flags &= ~CODEC_FLAG_AC_PRED; 
+      av_opt_set_int(m_context->priv_data, "structured_slices", 0, 0);
     return;
   }
 
@@ -360,9 +363,9 @@ void H263_Base_EncoderContext::SetOption
     // Annex K: Slice Structure
     // does not work with eyeBeam
     if (atoi(value) != 0)
-      m_context->flags |= CODEC_FLAG_H263P_SLICE_STRUCT; 
+      av_opt_set_int(m_context->priv_data, "structured_slices", 1, 0);
     else
-      m_context->flags &= ~CODEC_FLAG_H263P_SLICE_STRUCT; 
+      av_opt_set_int(m_context->priv_data, "structured_slices", 0, 0);
     return;
   }
 
@@ -370,9 +373,9 @@ void H263_Base_EncoderContext::SetOption
     // Annex S: Alternative INTER VLC mode
     // does not work with eyeBeam
     if (atoi(value) == 1)
-      m_context->flags |= CODEC_FLAG_H263P_AIV; 
+      av_opt_set_int(m_context->priv_data, "aiv", 1, 0);
     else
-      m_context->flags &= ~CODEC_FLAG_H263P_AIV; 
+      av_opt_set_int(m_context->priv_data, "aiv", 0, 0);
     return;
   }
 
@@ -434,9 +437,6 @@ bool H263_Base_EncoderContext::OpenCodec
   m_inputFrame->data[1] = m_inputFrame->data[0] + planeSize;
   m_inputFrame->data[2] = m_inputFrame->data[1] + (planeSize / 4);
 
-  if (m_context->width > 352)
-    m_context->flags &= ~CODEC_FLAG_EMU_EDGE; // Totally bizarre! FFMPEG crashes if on for CIF4
-
   // Dump info
   PTRACE(5, m_prefix, "Size is " << m_context->width << "x" << m_context->height);
   PTRACE(5, m_prefix, "GOP is " << m_context->gop_size);
@@ -450,16 +450,7 @@ bool H263_Base_EncoderContext::OpenCodec
   PTRACE(5, m_prefix, "qmax set to " << m_context->qmax);
   PTRACE(5, m_prefix, "payload size set to " << m_context->rtp_payload_size);
 
-  #define CODEC_TRACER_FLAG(tracer, flag) \
-    PTRACE(4, m_prefix, #flag " is " << ((m_context->flags & flag) ? "enabled" : "disabled"));
-  CODEC_TRACER_FLAG(tracer, CODEC_FLAG_H263P_UMV);
-  CODEC_TRACER_FLAG(tracer, CODEC_FLAG_OBMC);
-  CODEC_TRACER_FLAG(tracer, CODEC_FLAG_AC_PRED);
-  CODEC_TRACER_FLAG(tracer, CODEC_FLAG_H263P_SLICE_STRUCT)
-  CODEC_TRACER_FLAG(tracer, CODEC_FLAG_LOOP_FILTER);
-  CODEC_TRACER_FLAG(tracer, CODEC_FLAG_H263P_AIV);
-
-  return FFMPEGLibraryInstance.AvcodecOpen(m_context, m_codec) == 0;
+  return FFMPEGLibraryInstance.AvcodecOpen(m_context, m_codec, NULL) == 0;
 }
 
 void H263_Base_EncoderContext::CloseCodec()
@@ -521,7 +512,7 @@ bool H263_Base_EncoderContext::EncodeFra
 
     // Need to copy to local buffer to guarantee 16 byte alignment
     memcpy(m_inputFrame->data[0], OPAL_VIDEO_FRAME_DATA_PTR(header), header->width*header->height*3/2);
-    m_inputFrame->pict_type = (flags & PluginCodec_CoderForceIFrame) ? FF_I_TYPE : AV_PICTURE_TYPE_NONE;
+    m_inputFrame->pict_type = (flags & PluginCodec_CoderForceIFrame) ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_NONE;
 
     /*
     m_inputFrame->pts = (int64_t)srcRTP.GetTimestamp()*m_context->time_base.den/m_context->time_base.num/VIDEO_CLOCKRATE;
@@ -592,7 +583,7 @@ void H263_RFC2190_EncoderContext::RTPCal
 
 bool H263_RFC2190_EncoderContext::Init()
 {
-  if (!H263_Base_EncoderContext::Init(CODEC_ID_H263))
+  if (!H263_Base_EncoderContext::Init(AV_CODEC_ID_H263))
     return false;
 
 #if LIBAVCODEC_RTP_MODE
@@ -603,13 +594,13 @@ bool H263_RFC2190_EncoderContext::Init()
   m_context->rtp_callback = &H263_RFC2190_EncoderContext::RTPCallBack;
   m_context->opaque = this; // used to separate out packets from different encode threads
 
-  m_context->flags &= ~CODEC_FLAG_H263P_UMV;
+  av_opt_set_int(m_context->priv_data, "umv", 0, 0);
   m_context->flags &= ~CODEC_FLAG_4MV;
 #if LIBAVCODEC_RTP_MODE
   m_context->flags &= ~CODEC_FLAG_H263P_AIC;
 #endif
-  m_context->flags &= ~CODEC_FLAG_H263P_AIV;
-  m_context->flags &= ~CODEC_FLAG_H263P_SLICE_STRUCT;
+  av_opt_set_int(m_context->priv_data, "aiv", 0, 0);
+  av_opt_set_int(m_context->priv_data, "structured_slices", 0, 0);
 
   return true;
 }
@@ -629,7 +620,7 @@ H263_RFC2429_EncoderContext::~H263_RFC24
 
 bool H263_RFC2429_EncoderContext::Init()
 {
-  return H263_Base_EncoderContext::Init(CODEC_ID_H263P);
+  return H263_Base_EncoderContext::Init(AV_CODEC_ID_H263P);
 }
 
 
@@ -653,7 +644,7 @@ H263_Base_DecoderContext::H263_Base_Deco
   if (!FFMPEGLibraryInstance.Load())
     return;
 
-  if ((m_codec = FFMPEGLibraryInstance.AvcodecFindDecoder(CODEC_ID_H263)) == NULL) {
+  if ((m_codec = FFMPEGLibraryInstance.AvcodecFindDecoder(AV_CODEC_ID_H263)) == NULL) {
     PTRACE(1, m_prefix, "Codec not found for decoder");
     return;
   }
@@ -704,7 +695,7 @@ bool H263_Base_DecoderContext::OpenCodec
     return 0;
   }
 
-  if (FFMPEGLibraryInstance.AvcodecOpen(m_context, m_codec) < 0) {
+  if (FFMPEGLibraryInstance.AvcodecOpen(m_context, m_codec, NULL) < 0) {
     PTRACE(1, m_prefix, "Failed to open H.263 decoder");
     return false;
   }
