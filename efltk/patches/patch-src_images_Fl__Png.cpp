$NetBSD: patch-src_images_Fl__Png.cpp,v 1.1 2011/03/14 11:13:15 obache Exp $

--- src/images/Fl_Png.cpp.orig	2009-04-22 11:51:33.000000000 +0000
+++ src/images/Fl_Png.cpp
@@ -18,17 +18,17 @@ bool setup_png_transformations(png_struc
 static void my_png_warning(png_structp png_ptr, png_const_charp message)
 {
     const char *name = "PNG: Unknown (WARNING!)";
-    if (png_ptr != NULL && png_ptr->error_ptr != NULL)
-        name = (const char *)png_ptr->error_ptr;
+    if (png_ptr != NULL && png_get_error_ptr(png_ptr) != NULL)
+        name = (const char *)png_get_error_ptr(png_ptr);
     Fl::warning("%s: libpng warning: %s", name, message);
 }
 
 static void my_png_error(png_structp png_ptr, png_const_charp message)
 {
     png_last_error = (volatile char*)"PNG: Unknown (ERROR!)";
-    if (png_ptr != NULL && png_ptr->error_ptr != NULL)
+    if (png_ptr != NULL && png_get_error_ptr(png_ptr) != NULL)
         png_last_error = (volatile char*)message;
-    longjmp(png_ptr->jmpbuf, 0);
+    png_longjmp(png_ptr, 0);
 }
 
 static bool png_is_valid_file(const char *filename)
@@ -56,7 +56,7 @@ static bool png_is_valid_mem(const uint8
 // PNG READ METHODS:
 
 static void read_data_fn(png_structp png_ptr, png_bytep d, png_size_t length) {
-    ((Fl_IO*)png_ptr->io_ptr)->read(d, length);
+    ((Fl_IO*)png_get_io_ptr(png_ptr))->read(d, length);
 }
 
 #define return_error() \
@@ -81,7 +81,7 @@ static bool png_create(Fl_IO &png_io, ui
     if(!end_info_ptr) { return_error(); }
 
     png_bytepp rows = 0;
-    if(setjmp(png_ptr->jmpbuf)) {
+    if(setjmp(png_jmpbuf(png_ptr))) {
         if(rows) free(rows);
         if(png_ptr) png_destroy_read_struct (&png_ptr, &info_ptr, &end_info_ptr);
         fputs((const char *)png_last_error, stderr);
@@ -108,15 +108,15 @@ static bool png_create(Fl_IO &png_io, ui
         Rmask = 0x000000FF;
         Gmask = 0x0000FF00;
         Bmask = 0x00FF0000;
-        Amask = (info_ptr->channels == 4) ? 0xFF000000 : 0;
+        Amask = (png_get_channels(png_ptr, info_ptr) == 4) ? 0xFF000000 : 0;
 #else
-        int s = (info_ptr->channels == 4) ? 0 : 8;
+        int s = (png_get_channels(png_ptr, info_ptr) == 4) ? 0 : 8;
         Rmask = 0xFF000000 >> s;
         Gmask = 0x00FF0000 >> s;
         Bmask = 0x0000FF00 >> s;
         Amask = 0x000000FF >> s;
 #endif
-        if(info_ptr->channels == 4)
+        if(png_get_channels(png_ptr, info_ptr) == 4)
             fmt.masktype = FL_MASK_ALPHA;
     }
 
@@ -191,10 +191,10 @@ bool setup_png_transformations(png_struc
     /* Extract multiple pixels with bit depths of 1, 2, and 4 from a single
      * byte into separate bytes (useful for paletted and grayscale images).
      */
-    if (info_ptr->bit_depth < 8)
+    if (png_get_bit_depth(png_ptr, info_ptr) < 8)
         png_set_packing(png_ptr);
     /* tell libpng to strip 16 bit/color files down to 8 bits/color */
-    else if (info_ptr->bit_depth == 16)
+    else if (png_get_bit_depth(png_ptr, info_ptr) == 16)
         png_set_strip_16(png_ptr) ;
 
     /* scale greyscale values to the range 0..255 */
@@ -254,7 +254,7 @@ bool setup_png_transformations(png_struc
 // PNG WRITE METHODS:
 
 static void write_data_fn(png_structp png_ptr, png_bytep d, png_size_t length) {
-    ((Fl_IO*)png_ptr->io_ptr)->write(d, length);
+    ((Fl_IO*)png_get_io_ptr(png_ptr))->write(d, length);
     //png_io.write(d, length);
 }
 
@@ -318,7 +318,7 @@ static bool png_write(Fl_IO &png_io, con
 
     bool allocated = false;
     uint8 *wr_data = (uint8*)data;
-    if(setjmp(png_ptr->jmpbuf)) {
+    if(setjmp(png_jmpbuf(png_ptr))) {
         if(png_ptr) png_destroy_write_struct(&png_ptr, &info_ptr);
         if(allocated && wr_data) free(wr_data);
         return false;
