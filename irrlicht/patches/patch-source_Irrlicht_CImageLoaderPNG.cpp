$NetBSD: patch-source_Irrlicht_CImageLoaderPNG.cpp,v 1.1.1.1 2011/02/24 15:12:08 pallegra Exp $

--- source/Irrlicht/CImageLoaderPNG.cpp.orig	2010-10-24 09:42:46.000000000 +0000
+++ source/Irrlicht/CImageLoaderPNG.cpp
@@ -28,7 +28,7 @@ namespace video
 static void png_cpexcept_error(png_structp png_ptr, png_const_charp msg)
 {
 	os::Printer::log("PNG FATAL ERROR", msg, ELL_ERROR);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 // PNG function for file reading
@@ -37,7 +37,7 @@ void PNGAPI user_read_data_fcn(png_struc
 	png_size_t check;
 
 	// changed by zola {
-	io::IReadFile* file=(io::IReadFile*)png_ptr->io_ptr;
+	io::IReadFile* file=(io::IReadFile*)png_get_io_ptr(png_ptr);
 	check=(png_size_t) file->read((void*)data,(u32)length);
 	// }
 
@@ -162,7 +162,7 @@ IImage* CImageLoaderPng::loadImage(io::I
 	if (BitDepth < 8)
 	{
 		if (ColorType==PNG_COLOR_TYPE_GRAY || ColorType==PNG_COLOR_TYPE_GRAY_ALPHA)
-			png_set_gray_1_2_4_to_8(png_ptr);
+			png_set_expand_gray_1_2_4_to_8(png_ptr);
 		else
 			png_set_packing(png_ptr);
 	}
