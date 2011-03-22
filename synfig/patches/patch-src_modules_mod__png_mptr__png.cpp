$NetBSD: patch-src_modules_mod__png_mptr__png.cpp,v 1.2 2011/03/22 10:14:08 phonohawk Exp $

Fix build breakage on png-1.5.1

--- src/modules/mod_png/mptr_png.cpp.orig	2010-11-13 13:51:52.000000000 +0000
+++ src/modules/mod_png/mptr_png.cpp
@@ -301,15 +301,27 @@ png_mptr::png_mptr(const char *file_name
 		break;
 
 	case PNG_COLOR_TYPE_PALETTE:
+        png_colorp palette;
+        int num_palette;
+        png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette);
+
+        bool is_tRNS_valid;
+        png_bytep trans_alpha;
+        int num_trans;
+        png_color_16p trans_color;
+        is_tRNS_valid = png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS);
+        png_get_tRNS(png_ptr, info_ptr, &trans_alpha, &num_trans, &trans_color);
+
 		for(y=0;y<height;y++)
 			for(x=0;x<width;x++)
 			{
-				float r=gamma().r_U8_to_F32((unsigned char)png_ptr->palette[row_pointers[y][x]].red);
-				float g=gamma().g_U8_to_F32((unsigned char)png_ptr->palette[row_pointers[y][x]].green);
-				float b=gamma().b_U8_to_F32((unsigned char)png_ptr->palette[row_pointers[y][x]].blue);
+				float r=gamma().r_U8_to_F32((unsigned char)palette[row_pointers[y][x]].red);
+				float g=gamma().g_U8_to_F32((unsigned char)palette[row_pointers[y][x]].green);
+				float b=gamma().b_U8_to_F32((unsigned char)palette[row_pointers[y][x]].blue);
 				float a=1.0;
-				if(info_ptr->valid & PNG_INFO_tRNS)
-				    a = (float)(unsigned char)png_ptr->trans[row_pointers[y][x]]*(1.0/255.0);
+                if (is_tRNS_valid) {
+				    a = (float)(unsigned char)trans_alpha[row_pointers[y][x]]*(1.0/255.0);
+                }
 				surface_buffer[y][x]=Color(
 					r,
 					g,
