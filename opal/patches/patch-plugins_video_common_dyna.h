$NetBSD$

--- plugins/video/common/dyna.h.orig	2013-02-20 02:18:05.000000000 +0000
+++ plugins/video/common/dyna.h
@@ -88,16 +88,16 @@ class DynaLink
 class FFMPEGLibrary 
 {
   public:
-    FFMPEGLibrary(CodecID codec);
+    FFMPEGLibrary(AVCodecID codec);
     ~FFMPEGLibrary();
 
     bool Load();
 
-    AVCodec *AvcodecFindEncoder(enum CodecID id);
-    AVCodec *AvcodecFindDecoder(enum CodecID id);
+    AVCodec *AvcodecFindEncoder(enum AVCodecID id);
+    AVCodec *AvcodecFindDecoder(enum AVCodecID id);
     AVCodecContext *AvcodecAllocContext(void);
     AVFrame *AvcodecAllocFrame(void);
-    int AvcodecOpen(AVCodecContext *ctx, AVCodec *codec);
+    int AvcodecOpen(AVCodecContext *ctx, AVCodec *codec, AVDictionary **options);
     int AvcodecClose(AVCodecContext *ctx);
     int AvcodecEncodeVideo(AVCodecContext *ctx, BYTE *buf, int buf_size, const AVFrame *pict);
     int AvcodecDecodeVideo(AVCodecContext *ctx, AVFrame *pict, int *got_picture_ptr, BYTE *buf, int buf_size);
@@ -117,15 +117,15 @@ class FFMPEGLibrary 
     DynaLink m_libAvcodec;
     DynaLink m_libAvutil;
 
-    CodecID m_codec;
+    AVCodecID m_codec;
     char m_codecString[32];
 
     void (*Favcodec_init)(void);
     void (*Fav_init_packet)(AVPacket *pkt);
 
     void (*Favcodec_register_all)(void);
-    AVCodec *(*Favcodec_find_encoder)(enum CodecID id);
-    AVCodec *(*Favcodec_find_decoder)(enum CodecID id);
+    AVCodec *(*Favcodec_find_encoder)(enum AVCodecID id);
+    AVCodec *(*Favcodec_find_decoder)(enum AVCodecID id);
     AVCodecContext *(*Favcodec_alloc_context)(void);
     AVFrame *(*Favcodec_alloc_frame)(void);
     int (*Favcodec_open)(AVCodecContext *ctx, AVCodec *codec);
