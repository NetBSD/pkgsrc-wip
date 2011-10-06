$NetBSD: patch-src_png.c,v 1.1 2011/10/06 02:02:34 makoto Exp $

API changes from png 1.4 to 1.5
Also please note WRKSRC = flam3/src

--- src/png.c.orig	2011-09-28 19:39:43.000000000 +0900
+++ ./png.c	2011-10-06 10:53:27.000000000 +0900
@@ -144,7 +144,7 @@
   }
   if (setjmp(png_jmpbuf(png_ptr))) {
      if (png_image) {
-	 for (y = 0 ; y < info_ptr->height ; y++)
+        for (y = 0 ; y < png_get_image_height(png_ptr,info_ptr) ; y++)
 	     free (png_image[y]);
 	 free (png_image);
      }
@@ -163,19 +163,19 @@
   png_set_sig_bytes (png_ptr, SIG_CHECK_SIZE);
   png_read_info (png_ptr, info_ptr);
 
-  if (8 != info_ptr->bit_depth) {
+  if (8 != png_get_bit_depth(png_ptr, info_ptr)) {
     fprintf(stderr, "bit depth type must be 8, not %d.\n",
-	    info_ptr->bit_depth);
+	    png_get_bit_depth(png_ptr, info_ptr));
     return 0;
   }
 
-  *width = info_ptr->width;
-  *height = info_ptr->height;
+  *width = png_get_image_width(png_ptr, info_ptr);
+  *height = png_get_image_height(png_ptr, info_ptr);
   p = q = malloc(4 * *width * *height);
-  png_image = (png_byte **)malloc (info_ptr->height * sizeof (png_byte*));
+  png_image = (png_byte **)malloc (png_get_image_height(png_ptr, info_ptr) * sizeof (png_byte*));
 
-  linesize = info_ptr->width;
-  switch (info_ptr->color_type) {
+  linesize = png_get_image_width(png_ptr, info_ptr);
+  switch (png_get_color_type(png_ptr, info_ptr)) {
     case PNG_COLOR_TYPE_RGB:
       linesize *= 3;
       break;
@@ -184,21 +184,21 @@
       break;
   default:
     fprintf(stderr, "color type must be RGB or RGBA not %d.\n",
-	    info_ptr->color_type);
+	    png_get_color_type(png_ptr, info_ptr));
     return 0;
   }
 
-  for (y = 0 ; y < info_ptr->height ; y++) {
+  for (y = 0 ; y < png_get_image_height(png_ptr, info_ptr) ; y++) {
     png_image[y] = malloc (linesize);
   }
   png_read_image (png_ptr, png_image);
   png_read_end (png_ptr, info_ptr);
 
-  for (y = 0 ; y < info_ptr->height ; y++) {
+  for (y = 0 ; y < png_get_image_height(png_ptr, info_ptr) ; y++) {
     unsigned char *s = png_image[y];
-    for (x = 0 ; x < info_ptr->width ; x++) {
+    for (x = 0 ; x < png_get_image_width(png_ptr, info_ptr); x++) {
 
-      switch (info_ptr->color_type) {
+      switch (png_get_color_type (png_ptr, info_ptr)) {
       case PNG_COLOR_TYPE_RGB:
 	p[0] = s[0];
 	p[1] = s[1];
@@ -219,7 +219,7 @@
     }
   }
 
-  for (y = 0 ; y < info_ptr->height ; y++)
+  for (y = 0 ; y < png_get_image_height(png_ptr, info_ptr); y++)
     free (png_image[y]);
   free (png_image);
   png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp)NULL);  
