$NetBSD$

Support for DeePsea tall patches:
https://doomwiki.org/wiki/Picture_format#Tall_patches

This patch is for the hardware renderer.

--- src/hardware/hw_cache.c.orig	2020-07-07 09:01:37.000000000 +0000
+++ src/hardware/hw_cache.c
@@ -219,6 +219,8 @@ void HWR_DrawPatchInCache (Mipmap_t* mip
 
     for (block += col*bytepp; ncols--; block+=bytepp, xfrac+=xfracstep)
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         patchcol = (column_t *)((byte *)sw_patch
                                 + sw_patch->columnofs[xfrac>>16]);
 
@@ -226,9 +228,19 @@ void HWR_DrawPatchInCache (Mipmap_t* mip
 
         while (patchcol->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (patchcol->topdelta <= top)
+            {
+                top += patchcol->topdelta;
+            }
+            else
+            {
+                top = patchcol->topdelta;
+            }
             source = (byte *)patchcol + 3;
             count  = ((patchcol->length * scale_y) + (FRACUNIT/2)) >> 16;
-            ypos = originy + patchcol->topdelta;
+            ypos = originy + top;
+            //ypos = originy + patchcol->topdelta;
 
             yfrac = 0;
             //yfracstep = (patchcol->length << 16) / count;
