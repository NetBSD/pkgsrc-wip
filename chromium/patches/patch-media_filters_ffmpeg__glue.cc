$NetBSD: patch-media_filters_ffmpeg__glue.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- media/filters/ffmpeg_glue.cc.orig	2011-05-24 08:01:03.000000000 +0000
+++ media/filters/ffmpeg_glue.cc
@@ -44,7 +44,7 @@ static int WriteContext(URLContext* h, u
   return AVERROR_IO;
 }
 
-static int64 SeekContext(URLContext* h, int64 offset, int whence) {
+static int64_t SeekContext(URLContext* h, int64_t offset, int whence) {
   FFmpegURLProtocol* protocol = ToProtocol(h->priv_data);
   int64 new_offset = AVERROR_IO;
   switch (whence) {
