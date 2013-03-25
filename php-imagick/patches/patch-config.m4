$NetBSD: patch-config.m4,v 1.2 2013/03/25 12:58:01 fhajny Exp $

--- config.m4.orig	2012-05-30 20:21:12.000000000 +0000
+++ config.m4
@@ -32,6 +32,7 @@ if test $PHP_IMAGICK != "no"; then
 
   IMAGEMAGICK_VERSION_ORIG=`$WAND_BINARY --version`
   IMAGEMAGICK_VERSION_MASK=`echo ${IMAGEMAGICK_VERSION_ORIG} | awk 'BEGIN { FS = "."; } { printf "%d", ($1 * 1000 + $2) * 1000 + $3;}'`
+  IMAGEMAGICK_VERSION_MAJOR=`echo ${IMAGEMAGICK_VERSION_ORIG} | awk 'BEGIN { FS = "."; } { printf "%d", $1}'`
 
   AC_MSG_CHECKING(if ImageMagick version is at least 6.2.4)
   if test "$IMAGEMAGICK_VERSION_MASK" -ge 6002004; then
@@ -54,6 +55,8 @@ if test $PHP_IMAGICK != "no"; then
 
     if test -r $WAND_DIR/include/ImageMagick/wand/MagickWand.h; then
       AC_MSG_RESULT(found in $WAND_DIR/include/ImageMagick/wand/MagickWand.h)
+    elif test -r $WAND_DIR/include/ImageMagick-${IMAGEMAGICK_VERSION_MAJOR}/wand/MagickWand.h; then
+      AC_MSG_RESULT(found in $WAND_DIR/include/ImageMagick-${IMAGEMAGICK_VERSION_MAJOR}/wand/MagickWand.h)
     else
       AC_MSG_ERROR(Cannot locate header file MagickWand.h)
     fi
