$NetBSD: patch-source_Irrlicht_CImageWriterPNG.cpp,v 1.1.1.1 2011/02/24 15:12:08 pallegra Exp $

--- source/Irrlicht/CImageWriterPNG.cpp.orig	2010-10-24 09:42:48.000000000 +0000
+++ source/Irrlicht/CImageWriterPNG.cpp
@@ -35,7 +35,7 @@ IImageWriter* createImageWriterPNG()
 static void png_cpexcept_error(png_structp png_ptr, png_const_charp msg)
 {
 	os::Printer::log("PNG FATAL ERROR", msg, ELL_ERROR);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 // PNG function for file writing
@@ -43,7 +43,7 @@ void PNGAPI user_write_data_fcn(png_stru
 {
 	png_size_t check;
 
-	io::IWriteFile* file=(io::IWriteFile*)png_ptr->io_ptr;
+	io::IWriteFile* file=(io::IWriteFile*)png_get_io_ptr(png_ptr);
 	check=(png_size_t) file->write((const void*)data,(u32)length);
 
 	if (check != length)
