$NetBSD$

Support for DeePsea tall patches in textures.

New code is based on Crispy Doom Git commit:
c97a5c1d8054eab46856f71e4998d71760aa3339

--- src/r_data.c.orig	2020-07-07 09:01:41.000000000 +0000
+++ src/r_data.c
@@ -613,6 +613,7 @@ void R_DrawColumnInCache ( column_t*    
 {
     int         count;
     int         position;  // dest
+    int         top = -1;  // [crispy] Support for DeePsea tall patches
     byte*       source;
 //    byte*       dest;
 
@@ -622,11 +623,21 @@ void R_DrawColumnInCache ( column_t*    
     // Column is a series of posts (post_t), terminated by 0xFF
     while (colpost->topdelta != 0xff)	// end of posts
     {
+        // [crispy] Support for DeePsea tall patches
+        if (colpost->topdelta <= top)
+        {
+            top += colpost->topdelta;
+        }
+        else
+        {
+            top = colpost->topdelta;
+        }
         // post has 2 byte header (post_t), 
         // and has extra byte before and after pixel data
         source = (byte *)colpost + 3;	// pixel data after post header
         count = colpost->length;
-        position = originy + colpost->topdelta;  // position in dest
+        position = originy + top;  // [crispy] Support for DeePsea tall patches
+        //position = originy + colpost->topdelta;  // position in dest
 
         if (position < 0)
         {
