$NetBSD: patch-src_MOGL_MOGL__Image.cpp,v 1.1 2012/06/13 22:54:58 othyro Exp $

Needs old png 1.4 definitions and updated an API function name.

--- src/MOGL/MOGL_Image.cpp.orig	2006-03-07 20:53:33.000000000 +0000
+++ src/MOGL/MOGL_Image.cpp
@@ -25,6 +25,9 @@
 
 using namespace std;
 
+#define png_infopp_NULL (png_infopp)NULL
+#define int_p_NULL (int*)NULL
+
 #define PNG_BYTES_TO_CHECK 8
 
 MOGL_Image::MOGL_Image(bool p_AutoriserTrou)
@@ -235,7 +238,7 @@ bool MOGL_Image::ChargerPNG(const char *
   /* Expand grayscale images to the full 8 bits from 1, 2, or 4 bits/pixel */
   if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
   {
-    png_set_gray_1_2_4_to_8(png_ptr);
+    png_set_expand_gray_1_2_4_to_8(png_ptr);
   }
   
   /* Expand paletted or RGB images with transparency to full alpha channels
