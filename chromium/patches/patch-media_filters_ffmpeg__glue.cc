$NetBSD: patch-media_filters_ffmpeg__glue.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- media/filters/ffmpeg_glue.cc.orig	2011-04-13 08:01:06.000000000 +0000
+++ media/filters/ffmpeg_glue.cc
@@ -43,7 +43,7 @@ int WriteContext(URLContext* h, unsigned
   return AVERROR_IO;
 }
 
-int64 SeekContext(URLContext* h, int64 offset, int whence) {
+int64_t SeekContext(URLContext* h, int64_t offset, int whence) {
   media::FFmpegURLProtocol* protocol = ToProtocol(h->priv_data);
   int64 new_offset = AVERROR_IO;
   switch (whence) {
