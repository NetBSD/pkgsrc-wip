$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/r_sky.c.orig	2019-08-21 09:16:38.000000000 +0000
+++ src/r_sky.c
@@ -112,7 +112,7 @@ void R_Setup_SkyDraw (void)
     {
         W_ReadLumpHeader (texpatch->patchnum, &wpatch, sizeof(patch_t));
         // [WDJ] Do endian fix as this is read.
-        wpatch.height = LE_SWAP16(wpatch.height);
+        wpatch.height = (uint16_t)( LE_SWAP16(wpatch.height) );
         if( wpatch.height > max_height )
             max_height = wpatch.height;
         texpatch++;
