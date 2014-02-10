$NetBSD: patch-ffmpeg-php.c,v 1.1 2014/02/10 15:26:34 fhajny Exp $

Fix for recent ffmpeg (avcodec_init no longer provided/needed).
--- ffmpeg-php.c.orig	2008-10-13 19:00:08.000000000 +0000
+++ ffmpeg-php.c
@@ -90,9 +90,6 @@ PHP_INI_END()
  */
 PHP_MINIT_FUNCTION(ffmpeg)
 {
-    /* must be called before using avcodec libraries. */ 
-    avcodec_init();
-
     /* register all codecs */
     av_register_all();
     
