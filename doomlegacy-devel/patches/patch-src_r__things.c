$NetBSD$

Support for DeePsea tall patches in sprites (and masked mid textures):
https://doomwiki.org/wiki/Picture_format#Tall_patches

New code is based on Crispy Doom Git commit:
c97a5c1d8054eab46856f71e4998d71760aa3339

--- src/r_things.c.orig	2020-07-07 09:01:40.000000000 +0000
+++ src/r_things.c
@@ -1097,15 +1097,27 @@ fixed_t         dm_texturemid;
 void R_DrawMaskedColumn ( byte * column_data )
 {
     fixed_t     top_post_sc, bottom_post_sc;  // fixed_t screen coord.
+    int         top = -1;  // [crispy] Support for DeePsea tall patches
 
     column_t * column = (column_t*) column_data;
    
     // over all column posts for this column
     for ( ; column->topdelta != 0xff ; )
     {
+        // [crispy] Support for DeePsea tall patches
+        if (column->topdelta <= top)
+        {
+            top += column->topdelta;
+        }
+        else
+        {
+            top = column->topdelta;
+        }
         // calculate unclipped screen coordinates
         //  for post
-        top_post_sc = dm_top_patch + dm_yscale*column->topdelta;
+        // [crispy] Support for DeePsea tall patches
+        top_post_sc = dm_top_patch + dm_yscale*top;
+        //top_post_sc = dm_top_patch + dm_yscale*column->topdelta;
         bottom_post_sc = (dm_bottom_patch == FIXED_MAX) ?
             top_post_sc + dm_yscale*column->length
             : dm_bottom_patch + dm_yscale*column->length;
@@ -1154,7 +1166,10 @@ void R_DrawMaskedColumn ( byte * column_
 #endif
 
             dc_source = (byte *)column + 3;
-            dc_texturemid = dm_texturemid - (column->topdelta<<FRACBITS);
+            // [crispy] Support for DeePsea tall patches
+            dc_texturemid = dm_texturemid - (top<<FRACBITS);
+            // dc_source = (byte *)column + 3 - top;
+            // dc_texturemid = dm_texturemid - (column->topdelta<<FRACBITS);
             // dc_source = (byte *)column + 3 - column->topdelta;
             fog_col_length = column->length;
 
