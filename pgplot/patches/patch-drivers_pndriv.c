$NetBSD: patch-drivers_pndriv.c,v 1.1 2013/12/12 19:10:29 slitvinov Exp $

Patch is taken from http://svnweb.freebsd.org/ports/head/graphics/pgplot/Makefile

--- drivers/pndriv.c.orig	1999-03-27 02:06:23.000000000 +0000
+++ drivers/pndriv.c
@@ -222,7 +222,7 @@ static void write_image_file(DeviceData
 	return;
   }
 
-  if (setjmp(png_ptr->jmpbuf)) { /* not really sure what I'm doing here... */
+  if (setjmp(png_jmpbuf(png_ptr))) { /* not really sure what I'm doing here... */
 	fprintf(stderr,"%s: error in libpng while writing file %s, plotting disabled\n", png_ident, filename);
 	png_destroy_write_struct(&png_ptr,&info_ptr);
 	dev->error = true;
