$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/r_things.c.orig	2019-08-21 09:16:38.000000000 +0000
+++ src/r_things.c
@@ -572,10 +572,10 @@ boolean R_AddSingleSpriteDef (char* sprn
             // [WDJ] Do endian while translate temp to internal.
             spritelump_id = R_Get_spritelump();  // get next index, may expand and move the table
             spritelump_t * sl = &spritelumps[spritelump_id];  // sprite patch header
-            sl->width = LE_SWAP16(patch.width)<<FRACBITS;
+            sl->width = ((uint16_t)( LE_SWAP16(patch.width) ))<<FRACBITS;
             sl->leftoffset = LE_SWAP16(patch.leftoffset)<<FRACBITS;
             sl->topoffset = LE_SWAP16(patch.topoffset)<<FRACBITS;
-            sl->height = LE_SWAP16(patch.height)<<FRACBITS;
+            sl->height = ((uint16_t)( LE_SWAP16(patch.height) ))<<FRACBITS;
 
 #ifdef HWRENDER
             //BP: we cannot use special trick in hardware mode because feet in ground caused by z-buffer
@@ -583,7 +583,7 @@ boolean R_AddSingleSpriteDef (char* sprn
             {
                 // topoffset may be negative, use signed compare
                 int16_t p_topoffset = LE_SWAP16(patch.topoffset);
-                int16_t p_height = LE_SWAP16(patch.height);
+                int16_t p_height = (uint16_t)( LE_SWAP16(patch.height) );
                 if( p_topoffset>0 && p_topoffset<p_height) // not for psprite
                 {
                     // perfect is patch.height but sometime it is too high
