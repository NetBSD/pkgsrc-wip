$NetBSD: patch-config.m4,v 1.1 2012/08/23 20:08:20 fhajny Exp $

--- config.m4.orig	2008-10-14 02:47:18.000000000 +0000
+++ config.m4
@@ -95,7 +95,7 @@ if test "$PHP_FFMPEG" != "no"; then
   LIBS=$SAVED_LIBS
   CFLAGS=$SAVED_CFLAGS
 
-  if test "$enable_ffmpeg_swscale" == yes; then
+  if test "$enable_ffmpeg_swscale" = yes; then
      AC_DEFINE(HAVE_SWSCALER, 1, [Define to 1 if software scaler is compiled into ffmpeg])
      PHP_ADD_LIBRARY_WITH_PATH(swscale, $FFMPEG_LIBDIR, FFMPEG_SHARED_LIBADD)
   else
