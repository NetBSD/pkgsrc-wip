$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/r_data.c.orig	2019-08-21 09:16:38.000000000 +0000
+++ src/r_data.c
@@ -1587,13 +1587,13 @@ void R_Load_Textures (void)
         // Texture struct allocation is dependent upon number of patches.
         texture = textures[i] =
             Z_Malloc (sizeof(texture_t)
-                      + sizeof(texpatch_t)*(LE_SWAP16(mtexture->patchcount)-1),
+                      + sizeof(texpatch_t)*((uint16_t)(LE_SWAP16(mtexture->patchcount))-1),
                       PU_STATIC, 0);
 
         // get texture info from texture lump
-        texture->width  = LE_SWAP16(mtexture->width);
-        texture->height = LE_SWAP16(mtexture->height);
-        texture->patchcount = LE_SWAP16(mtexture->patchcount);
+        texture->width  = (uint16_t)( LE_SWAP16(mtexture->width) );
+        texture->height = (uint16_t)( LE_SWAP16(mtexture->height) );
+        texture->patchcount = (uint16_t)( LE_SWAP16(mtexture->patchcount) );
         texture->texture_model = (mtexture->masked)? TM_masked : TM_none; // hint
 
         // Sparc requires memmove, becuz gcc doesn't know mtexture is not aligned.
@@ -1611,7 +1611,7 @@ void R_Load_Textures (void)
             // get texture patch info from texture lump
             texpatch->originx = LE_SWAP16(mpatch->originx);
             texpatch->originy = LE_SWAP16(mpatch->originy);
-            texpatch->patchnum = patch_to_num[LE_SWAP16(mpatch->patchnum)];
+            texpatch->patchnum = patch_to_num[ (uint16_t)( LE_SWAP16(mpatch->patchnum) )];
             if (texpatch->patchnum == -1)
             {
                 I_Error ("R_Load_Textures: Missing patch in texture %s\n",
