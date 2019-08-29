$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/w_wad.c.orig	2019-08-21 09:16:55.000000000 +0000
+++ src/w_wad.c
@@ -900,8 +900,8 @@ void* W_CachePatchNum_Endian ( lumpnum_t
     // [WDJ] If newly read patch then fix endian.
     if( lump_read )
     {
-        patch->height = LE_SWAP16(patch->height);
-        patch->width = LE_SWAP16(patch->width);
+        patch->height = (uint16_t)( LE_SWAP16(patch->height) );
+        patch->width = (uint16_t)( LE_SWAP16(patch->width) );
         patch->topoffset = LE_SWAP16(patch->topoffset);
         patch->leftoffset = LE_SWAP16(patch->leftoffset);
         {
@@ -1094,8 +1094,8 @@ void* W_CachePicNum( lumpnum_t lumpnum, 
     // [WDJ] If newly read pic then fix endian.
     if( lump_read )
     {
-        pt->height = LE_SWAP16(pt->height);
-        pt->width = LE_SWAP16(pt->width);
+        pt->height = (uint16_t)( LE_SWAP16(pt->height) );
+        pt->width = (uint16_t)( LE_SWAP16(pt->width) );
 //        pt->reserved = LE_SWAP16(pt->reserved);
     }
     return pt;
