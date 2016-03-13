$NetBSD: patch-plugins_video_common_dyna.cxx,v 1.1 2011/12/04 22:06:04 marino Exp $

--- plugins/video/common/dyna.cxx.orig	2013-02-20 02:18:05.000000000 +0000
+++ plugins/video/common/dyna.cxx
@@ -210,14 +210,14 @@ static void logCallbackFFMPEG(void * avc
 #endif
 
 
-FFMPEGLibrary::FFMPEGLibrary(CodecID codec)
+FFMPEGLibrary::FFMPEGLibrary(AVCodecID codec)
 {
   m_codec = codec;
-  if (m_codec==CODEC_ID_H264)
+  if (m_codec==AV_CODEC_ID_H264)
       snprintf( m_codecString, sizeof(m_codecString), "H264");
-  if (m_codec==CODEC_ID_H263P)
+  if (m_codec==AV_CODEC_ID_H263P)
       snprintf( m_codecString, sizeof(m_codecString), "H263+");
-  if (m_codec==CODEC_ID_MPEG4)
+  if (m_codec==AV_CODEC_ID_MPEG4)
       snprintf( m_codecString, sizeof(m_codecString), "MPEG4");
   m_isLoadedOK = false;
 }
@@ -348,12 +348,12 @@ bool FFMPEGLibrary::Load()
   return true;
 }
 
-AVCodec *FFMPEGLibrary::AvcodecFindEncoder(enum CodecID id)
+AVCodec *FFMPEGLibrary::AvcodecFindEncoder(enum AVCodecID id)
 {
   return Favcodec_find_encoder(id);
 }
 
-AVCodec *FFMPEGLibrary::AvcodecFindDecoder(enum CodecID id)
+AVCodec *FFMPEGLibrary::AvcodecFindDecoder(enum AVCodecID id)
 {
   WaitAndSignal m(processLock);
 
@@ -374,7 +374,7 @@ AVFrame *FFMPEGLibrary::AvcodecAllocFram
   return Favcodec_alloc_frame();
 }
 
-int FFMPEGLibrary::AvcodecOpen(AVCodecContext *ctx, AVCodec *codec)
+int FFMPEGLibrary::AvcodecOpen(AVCodecContext *ctx, AVCodec *codec, AVDictionary **options)
 {
   WaitAndSignal m(processLock);
 
