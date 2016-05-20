$NetBSD$

Adjust for ImageMagick-7.

--- zbarimg/zbarimg.c.orig	2009-10-23 18:16:44.000000000 +0000
+++ zbarimg/zbarimg.c
@@ -38,7 +38,7 @@
 #include <assert.h>
 
 #include <zbar.h>
-#include <wand/MagickWand.h>
+#include <MagickWand/MagickWand.h>
 
 /* in 6.4.5.4 MagickGetImagePixels changed to MagickExportImagePixels.
  * (still not sure this check is quite right...
