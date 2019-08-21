$NetBSD$

Correctly convert the 16-Bit blockmap offset (as imported from wad) to the
32-Bit format of the engine. On big endian machines this can overrun the
int16_t data type which leads to 32-Bit values padded with ones instead of
zeros.

--- src/p_setup.c.orig	2019-08-21 08:45:39.000000000 +0000
+++ src/p_setup.c
@@ -149,6 +149,8 @@
 //
 //-----------------------------------------------------------------------------
 
+#include "inttypes.h"
+
 #include "doomincl.h"
 #include "p_local.h"
 #include "p_tick.h"
@@ -1338,6 +1340,7 @@ void P_LoadBlockMap (int lump)
   bmaporgy = blockmaphead[1]<<FRACBITS;
   bmapwidth = blockmaphead[2];
   bmapheight = blockmaphead[3];
+  printf("[MB] Blockmap size (X/Y): %d/%d\n", bmapwidth, bmapheight);
   blockmapindex = & blockmaphead[4];
   firstlist = 4 + (bmapwidth*bmapheight);
   lastlist = count - 1;
@@ -1348,7 +1351,9 @@ void P_LoadBlockMap (int lump)
   // read blockmap index array
   for (i=4 ; i<firstlist ; i++)  // for all entries in wad offset index
   {
-      uint32_t  bme = LE_SWAP16(wadblockmaplump[i]);  // offset
+      printf("[MB] Raw blockmap offset: %d\n", LE_SWAP16(wadblockmaplump[i]));
+      uint32_t  bme = (uint16_t) LE_SWAP16(wadblockmaplump[i]);  // offset
+      printf("[MB] Cooked blockmap offset: 0x%08"PRIX32"\n", bme);
       // upon overflow, the bme will wrap to low values
       if ( (bme < firstlist)  // too small to be valid
            && (bme < 0x1000) && (prev_bme > 0xf000))  // wrapped
