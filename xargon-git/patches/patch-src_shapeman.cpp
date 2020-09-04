$NetBSD$

"c" is used as an array index, as a "byte" is causes a segmentation fault.

--- src/shapeman.cpp.orig	2020-08-19 22:41:06.000000000 +0000
+++ src/shapeman.cpp
@@ -58,7 +58,7 @@ void xlate_table (int n, char *addr, cha
 	uint16_t len_cga, len_ega, len_vga, len;
 	byte xs, xsb, ys;
 	byte storetype;
-	byte c;
+	int c;
 	int16_t x,y,b,flags;
 	//uint16_t x,y,flags;
 	//int b;
