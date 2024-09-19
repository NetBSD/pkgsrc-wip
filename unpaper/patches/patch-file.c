$NetBSD$

This ensures that we close the context and streams that are created from
libav; this might still not be complete, but there seems to be different
APIs between libav and ffmpeg so I'm changing one piece at a time.

Works towards closing Issue #26.

--- file.c
+++ file.c
@@ -105,7 +105,7 @@ void loadImage(const char *filename, AVFrame **image) {
     case AV_PIX_FMT_RGB24:
     case AV_PIX_FMT_MONOBLACK:
     case AV_PIX_FMT_MONOWHITE:
-        *image = frame;
+        *image = av_frame_clone(frame);
         break;
 
     case AV_PIX_FMT_PAL8:
@@ -123,6 +123,10 @@ void loadImage(const char *filename, AVFrame **image) {
     default:
         errOutput("unable to open file %s: unsupported pixel format", filename);
     }
+
+    avcodec_close(avctx);
+    av_free(avctx);
+    avformat_close_input(&s);
 }
 
 
@@ -134,13 +138,14 @@ void loadImage(const char *filename, AVFrame **image) {
  * @param type filetype of the image to save
  * @return true on success, false on failure
  */
-void saveImage(char *filename, AVFrame *image, int outputPixFmt) {
+void saveImage(char *filename, AVFrame *input, int outputPixFmt) {
     AVOutputFormat *fmt = NULL;
     enum AVCodecID output_codec = -1;
     AVCodec *codec;
     AVFormatContext *out_ctx;
     AVCodecContext *codec_ctx;
     AVStream *video_st;
+    AVFrame *output = input;
     int ret;
     char errbuff[1024];
 
@@ -174,13 +179,11 @@ void saveImage(char *filename, AVFrame *image, int outputPixFmt) {
         break;
     }
 
-    if ( image->format != outputPixFmt ) {
-        AVFrame *output;
-        initImage(&output, image->width, image->height,
+    if ( input->format != outputPixFmt ) {
+        initImage(&output, input->width, input->height,
                   outputPixFmt, -1);
-        copyImageArea(0, 0, image->width, image->height,
-                      image, 0, 0, output);
-        image = output;
+        copyImageArea(0, 0, input->width, input->height,
+                      input, 0, 0, output);
     }
 
     codec = avcodec_find_encoder(output_codec);
@@ -194,9 +197,9 @@ void saveImage(char *filename, AVFrame *image, int outputPixFmt) {
     }
 
     codec_ctx = video_st->codec;
-    codec_ctx->width = image->width;
-    codec_ctx->height = image->height;
-    codec_ctx->pix_fmt = image->format;
+    codec_ctx->width = output->width;
+    codec_ctx->height = output->height;
+    codec_ctx->pix_fmt = output->format;
     video_st->time_base.den = codec_ctx->time_base.den = 1;
     video_st->time_base.num = codec_ctx->time_base.num = 1;
 
@@ -221,7 +224,7 @@ void saveImage(char *filename, AVFrame *image, int outputPixFmt) {
     av_init_packet(&pkt);
 
     /* encode the image */
-    ret = avcodec_encode_video2(video_st->codec, &pkt, image, &got_packet);
+    ret = avcodec_encode_video2(video_st->codec, &pkt, output, &got_packet);
 
     if (ret < 0) {
         av_strerror(ret, errbuff, sizeof(errbuff));
@@ -237,6 +240,9 @@ void saveImage(char *filename, AVFrame *image, int outputPixFmt) {
 
     avio_close(out_ctx->pb);
     av_free(out_ctx);
+
+    if ( output != input )
+        av_frame_free(&output);
 }
 
 /**
