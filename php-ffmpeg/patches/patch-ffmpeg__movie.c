$NetBSD: patch-ffmpeg__movie.c,v 1.1 2013/02/22 10:48:45 jonperkin Exp $

Apply upstream fixes for newer ffmpeg.

--- ffmpeg_movie.c.orig	2008-10-13 22:46:53.000000000 +0000
+++ ffmpeg_movie.c
@@ -36,6 +36,8 @@
 
 #include <avcodec.h>
 #include <avformat.h>
+#include <pixfmt.h>
+#include <pixdesc.h>
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
@@ -68,6 +70,11 @@
 #define GET_CODEC_PTR(codec) &codec
 #endif
 
+/* XXX: arbitrary, should use av_realloc() */
+#ifndef MAX_STREAMS
+#define MAX_STREAMS 16
+#endif
+
 typedef struct {
     AVFormatContext *fmt_ctx;
     AVCodecContext *codec_ctx[MAX_STREAMS];
@@ -149,7 +156,7 @@ static int _php_get_stream_index(AVForma
  */
 static AVStream *_php_get_video_stream(AVFormatContext *fmt_ctx)
 {
-    int i = _php_get_stream_index(fmt_ctx, CODEC_TYPE_VIDEO);
+    int i = _php_get_stream_index(fmt_ctx, AVMEDIA_TYPE_VIDEO);
     
     return i < 0 ? NULL : fmt_ctx->streams[i];
 }
@@ -162,7 +169,7 @@ static AVStream *_php_get_video_stream(A
  */
 static AVStream *_php_get_audio_stream(AVFormatContext *fmt_ctx)
 {
-    int i = _php_get_stream_index(fmt_ctx, CODEC_TYPE_AUDIO);
+    int i = _php_get_stream_index(fmt_ctx, AVMEDIA_TYPE_AUDIO);
     
     return i < 0 ? NULL : fmt_ctx->streams[i];
 }
@@ -250,17 +257,17 @@ static int _php_open_movie_file(ff_movie
         char* filename)
 {
     if (ffmovie_ctx->fmt_ctx) {
-        av_close_input_file(ffmovie_ctx->fmt_ctx);
+        avformat_close_input(&ffmovie_ctx->fmt_ctx);
         ffmovie_ctx->fmt_ctx = NULL;
     }
     
     /* open the file with generic libav function */
-    if (av_open_input_file(&ffmovie_ctx->fmt_ctx, filename, NULL, 0, NULL) < 0) {
+    if (avformat_open_input(&ffmovie_ctx->fmt_ctx, filename, NULL, NULL) < 0) {
         return 1;
     }
 
     /* decode the first frames to get the stream parameters. */
-    av_find_stream_info(ffmovie_ctx->fmt_ctx);
+    avformat_find_stream_info(ffmovie_ctx->fmt_ctx, NULL);
 
     return 0;
 }
@@ -308,7 +315,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, __constr
     } 
 
     if (persistent) {
-        list_entry *le;
+        zend_rsrc_list_entry *le;
         /* resolve the fully-qualified path name to use as the hash key */
         fullpath = expand_filepath(filename, NULL TSRMLS_CC);
 
@@ -343,7 +350,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, __constr
             }
             
         } else { /* no existing persistant movie, create one */
-            list_entry new_le;
+            zend_rsrc_list_entry new_le;
             ffmovie_ctx = _php_alloc_ffmovie_ctx(1);
 
             if (_php_open_movie_file(ffmovie_ctx, filename)) {
@@ -357,7 +364,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, __constr
             new_le.ptr = ffmovie_ctx;
 
             if (FAILURE == zend_hash_update(&EG(persistent_list), hashkey, 
-                        hashkey_length+1, (void *)&new_le, sizeof(list_entry),
+                        hashkey_length+1, (void *)&new_le, sizeof(zend_rsrc_list_entry),
                         NULL)) {
                 php_error_docref(NULL TSRMLS_CC, E_WARNING, 
                         "Failed to register persistent resource");
@@ -414,7 +421,7 @@ static void _php_free_ffmpeg_movie(zend_
         }
     }
 
-    av_close_input_file(ffmovie_ctx->fmt_ctx);
+    avformat_close_input(&ffmovie_ctx->fmt_ctx);
 
     efree(ffmovie_ctx);
 }
@@ -438,7 +445,7 @@ static void _php_free_ffmpeg_pmovie(zend
         }
     }
 
-    av_close_input_file(ffmovie_ctx->fmt_ctx);
+    avformat_close_input(&ffmovie_ctx->fmt_ctx);
 
     free(ffmovie_ctx);
 }
@@ -481,7 +488,7 @@ static AVCodecContext* _php_get_decoder_
     stream_index = _php_get_stream_index(ffmovie_ctx->fmt_ctx, stream_type);
     if (stream_index < 0) {
         // FIXME: factor out the conditional.
-        if (stream_type == CODEC_TYPE_VIDEO) {
+        if (stream_type == AVMEDIA_TYPE_VIDEO) {
             zend_error(E_WARNING, "Can't find video stream in %s", 
                     _php_get_filename(ffmovie_ctx));
             return NULL;
@@ -510,7 +517,7 @@ static AVCodecContext* _php_get_decoder_
             GET_CODEC_PTR(ffmovie_ctx->fmt_ctx->streams[stream_index]->codec);
 
        /* open the decoder */
-        if (avcodec_open(ffmovie_ctx->codec_ctx[stream_index], decoder) < 0) {
+        if (avcodec_open2(ffmovie_ctx->codec_ctx[stream_index], decoder, NULL) < 0) {
             zend_error(E_WARNING, "Could not open codec for %s", _php_get_filename(ffmovie_ctx));
             return NULL;
         }
@@ -528,8 +535,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getComme
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
     
-    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->comment,
-            strlen(ffmovie_ctx->fmt_ctx->comment), 1);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "comment", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -543,8 +551,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getTitle
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->title,
-            strlen(ffmovie_ctx->fmt_ctx->title), 1);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "title", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -558,8 +567,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAutho
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->author,
-            strlen(ffmovie_ctx->fmt_ctx->author), 1);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "author", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -572,8 +582,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getCopyr
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->copyright,
-            strlen(ffmovie_ctx->fmt_ctx->copyright), 1);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "copyright", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -587,8 +598,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAlbum
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->album,
-            strlen(ffmovie_ctx->fmt_ctx->album), 1);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "album", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -601,8 +613,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getGenre
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->genre,
-            strlen(ffmovie_ctx->fmt_ctx->genre), 1);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "genre", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -616,7 +629,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getTrack
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
     
-    RETURN_LONG(ffmovie_ctx->fmt_ctx->track);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "track", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -629,7 +644,9 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getYear)
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
     
-    RETURN_LONG(ffmovie_ctx->fmt_ctx->year);
+    AVDictionaryEntry *m_entry = av_dict_get(ffmovie_ctx->fmt_ctx->metadata, "year", NULL, 0);
+
+    RETURN_STRINGL(m_entry->value, strlen(m_entry->value), 1);
 }
 /* }}} */
 
@@ -675,7 +692,7 @@ static float _php_get_framerate(ff_movie
     }
 
 #if LIBAVCODEC_BUILD > 4753 
-    if (GET_CODEC_FIELD(st->codec, codec_type) == CODEC_TYPE_VIDEO){
+    if (GET_CODEC_FIELD(st->codec, codec_type) == AVMEDIA_TYPE_VIDEO){
         if (st->r_frame_rate.den && st->r_frame_rate.num) {
             rate = av_q2d(st->r_frame_rate);
         } else {
@@ -807,7 +824,7 @@ static long _php_get_framenumber(ff_movi
 {
     AVCodecContext *decoder_ctx = NULL;
 
-    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO);
+    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, AVMEDIA_TYPE_VIDEO);
     if (!decoder_ctx) {
         return 0;
     }
@@ -847,7 +864,7 @@ static int _php_get_pixelformat(ff_movie
 {
     AVCodecContext *decoder_ctx;
     
-    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO);
+    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, AVMEDIA_TYPE_VIDEO);
 
     return decoder_ctx ? decoder_ctx->pix_fmt : 0;
 }
@@ -865,7 +882,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getPixel
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
     pix_fmt = _php_get_pixelformat(ffmovie_ctx);
-    fmt = avcodec_get_pix_fmt_name(pix_fmt);
+    fmt = av_get_pix_fmt_name(pix_fmt);
     
     if (fmt) {
         /* cast const to non-const to keep compiler from complaining, 
@@ -960,7 +977,7 @@ static const char* _php_get_codec_name(f
         codec_name = decoder_ctx->codec_name;
     } else {
         /* output avi tags */
-        if (decoder_ctx->codec_type == CODEC_TYPE_VIDEO) {
+        if (decoder_ctx->codec_type == AVMEDIA_TYPE_VIDEO) {
             snprintf(buf1, sizeof(buf1), "%c%c%c%c",
                     decoder_ctx->codec_tag & 0xff,
                     (decoder_ctx->codec_tag >> 8) & 0xff,
@@ -986,7 +1003,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getVideo
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    codec_name = (char*)_php_get_codec_name(ffmovie_ctx, CODEC_TYPE_VIDEO);
+    codec_name = (char*)_php_get_codec_name(ffmovie_ctx, AVMEDIA_TYPE_VIDEO);
  
     if (codec_name) {
         RETURN_STRINGL(codec_name, strlen(codec_name), 1);
@@ -1006,7 +1023,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAudio
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    codec_name = (char*)_php_get_codec_name(ffmovie_ctx, CODEC_TYPE_AUDIO);
+    codec_name = (char*)_php_get_codec_name(ffmovie_ctx, AVMEDIA_TYPE_AUDIO);
  
     if (codec_name) {
         RETURN_STRINGL(codec_name, strlen(codec_name), 1);
@@ -1026,7 +1043,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getVideo
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
    
-    stream_id= _php_get_stream_index(ffmovie_ctx->fmt_ctx, CODEC_TYPE_VIDEO); 
+    stream_id= _php_get_stream_index(ffmovie_ctx->fmt_ctx, AVMEDIA_TYPE_VIDEO); 
 
 	if( stream_id == -1 )
 	{
@@ -1048,7 +1065,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAudio
     
     GET_MOVIE_RESOURCE(ffmovie_ctx);
    
-    stream_id= _php_get_stream_index(ffmovie_ctx->fmt_ctx, CODEC_TYPE_AUDIO); 
+    stream_id= _php_get_stream_index(ffmovie_ctx->fmt_ctx, AVMEDIA_TYPE_AUDIO); 
 
 	if( stream_id == -1 )
 	{
@@ -1086,7 +1103,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAudio
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    channels = _php_get_codec_channels(ffmovie_ctx, CODEC_TYPE_AUDIO);
+    channels = _php_get_codec_channels(ffmovie_ctx, AVMEDIA_TYPE_AUDIO);
  
     if (channels) {
         RETURN_LONG(channels);
@@ -1122,7 +1139,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAudio
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    sample_rate = _php_get_codec_sample_rate(ffmovie_ctx, CODEC_TYPE_AUDIO);
+    sample_rate = _php_get_codec_sample_rate(ffmovie_ctx, AVMEDIA_TYPE_AUDIO);
  
     if (sample_rate) {
         RETURN_LONG(sample_rate);
@@ -1158,7 +1175,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getAudio
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    bit_rate = _php_get_codec_bit_rate(ffmovie_ctx, CODEC_TYPE_AUDIO);
+    bit_rate = _php_get_codec_bit_rate(ffmovie_ctx, AVMEDIA_TYPE_AUDIO);
  
     if (bit_rate) {
         RETURN_LONG(bit_rate);
@@ -1178,7 +1195,7 @@ FFMPEG_PHP_METHOD(ffmpeg_movie, getVideo
 
     GET_MOVIE_RESOURCE(ffmovie_ctx);
 
-    bit_rate = _php_get_codec_bit_rate(ffmovie_ctx, CODEC_TYPE_VIDEO);
+    bit_rate = _php_get_codec_bit_rate(ffmovie_ctx, AVMEDIA_TYPE_VIDEO);
  
     if (bit_rate) {
         RETURN_LONG(bit_rate);
@@ -1201,7 +1218,7 @@ static AVFrame* _php_read_av_frame(ff_mo
     int got_frame; 
 
     video_stream = _php_get_stream_index(ffmovie_ctx->fmt_ctx, 
-            CODEC_TYPE_VIDEO);
+            AVMEDIA_TYPE_VIDEO);
     if (video_stream < 0) {
         return NULL;
     }
@@ -1212,11 +1229,10 @@ static AVFrame* _php_read_av_frame(ff_mo
     while (av_read_frame(ffmovie_ctx->fmt_ctx, &packet) >= 0) {
         if (packet.stream_index == video_stream) {
         
-            avcodec_decode_video(decoder_ctx, frame, &got_frame,
-                    packet.data, packet.size);
+            avcodec_decode_video2(decoder_ctx, frame, &got_frame, &packet);
         
             if (got_frame) {
-                *is_keyframe = (packet.flags & PKT_FLAG_KEY);
+                *is_keyframe = (packet.flags & AV_PKT_FLAG_KEY);
                 *pts = packet.pts;
                 av_free_packet(&packet);
                 return frame;
@@ -1243,7 +1259,7 @@ static AVFrame* _php_get_av_frame(ff_mov
     AVCodecContext *decoder_ctx = NULL;
     AVFrame *frame = NULL;
 
-    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO);
+    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, AVMEDIA_TYPE_VIDEO);
     if (decoder_ctx == NULL) {
         return NULL;
     }
@@ -1275,14 +1291,15 @@ static AVFrame* _php_get_av_frame(ff_mov
         frame = _php_read_av_frame(ffmovie_ctx, decoder_ctx, is_keyframe, pts);
 
         /* hurry up if we're still a ways from the target frame */
-        if (wanted_frame != GETFRAME_KEYFRAME &&
+        /*if (wanted_frame != GETFRAME_KEYFRAME &&
                 wanted_frame != GETFRAME_NEXTFRAME &&
                 wanted_frame - ffmovie_ctx->frame_number > 
                 decoder_ctx->gop_size + 1) {
             decoder_ctx->hurry_up = 1;
         } else {
             decoder_ctx->hurry_up = 0;
-        }
+        } */
+        /*CUT? cannot hurry up ffmpeg anymore*/
         ffmovie_ctx->frame_number++; 
 
         /* 
@@ -1440,7 +1457,7 @@ static double _php_get_sample_aspect_rat
     AVCodecContext *decoder_ctx;
 	
 
-    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO);
+    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, AVMEDIA_TYPE_VIDEO);
     if (!decoder_ctx) {
         return -1;
     }
