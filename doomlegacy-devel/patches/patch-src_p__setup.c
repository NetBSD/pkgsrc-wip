$NetBSD$

Add support to internally create blockmap.
https://sourceforge.net/p/doomlegacy/feature-requests/96/

--- src/p_setup.c.orig	2021-09-27 10:05:53.000000000 +0000
+++ src/p_setup.c
@@ -150,6 +150,8 @@
 //-----------------------------------------------------------------------------
 
 #include "doomincl.h"
+#include "m_argv.h"      // [MB] 2020-05-13: To check for "-blockmap" option
+#include "p_blockmap.h"  // [MB] 2020-05-13: For internal blockmap creation
 #include "p_local.h"
 #include "p_tick.h"
   // think
@@ -256,14 +258,15 @@ typedef struct mapdata_s {
 // Created from axis aligned bounding box of the map, a rectangular array of
 // blocks of size ...
 // Used to speed up collision detection by spatial subdivision in 2D.
+// [MB] 2020-05-13: Fix comments (blockmapindex points to offset part of lump)
 //
 // Blockmap size.
 unsigned int    bmapwidth;
 unsigned int    bmapheight;     // size in mapblocks
 
-uint32_t *      blockmapindex;       // for large maps, wad is 16bit
-// offsets in blockmap are from here
-uint32_t *      blockmaphead; // Big blockmap, SSNTails
+uint32_t *      blockmaphead;   // Big blockmap, SSNTails
+uint32_t *      blockmapindex;  // For large maps, wad is 16bit
+                                // (offsets in blockmap are from here)
 
 // origin of block map
 // The bottom left corner of the most SW block.
@@ -2211,14 +2214,25 @@ boolean P_SetupLevel (int      to_episod
     }
 
     // note: most of this ordering is important
-    P_LoadBlockMap (level_lumpnum+ML_BLOCKMAP);
-    P_LoadVertexes (level_lumpnum+ML_VERTEXES);
-    P_LoadSectors  (level_lumpnum+ML_SECTORS);
-    P_LoadSideDefs (level_lumpnum+ML_SIDEDEFS);
-
-    P_LoadLineDefs (level_lumpnum+ML_LINEDEFS);
-    P_LoadSideDefs2(level_lumpnum+ML_SIDEDEFS);
-    P_LoadLineDefs2();
+    {
+        // [MB] 2020-05-13: Added option to internally create blockmap
+        boolean create_blockmap = M_CheckParm("-blockmap");
+
+        if (!create_blockmap)
+            P_LoadBlockMap (level_lumpnum+ML_BLOCKMAP);
+        P_LoadVertexes (level_lumpnum+ML_VERTEXES);
+        P_LoadSectors  (level_lumpnum+ML_SECTORS);
+        P_LoadSideDefs (level_lumpnum+ML_SIDEDEFS);
+        P_LoadLineDefs (level_lumpnum+ML_LINEDEFS);
+        P_LoadSideDefs2(level_lumpnum+ML_SIDEDEFS);
+        P_LoadLineDefs2();
+        // [MB] 2020-05-13: Internally create blockmap on request
+        if (create_blockmap)
+        {
+            GenPrintf(EMSG_info, "Ignore BLOCKMAP lump, create blockmap\n" );
+            P_CreateBlockMap ();
+        }
+    }
 
 #ifdef DEEPSEA_EXTENDED_NODES
     // [MB] 2020-04-21: Hook in code imported from woof 1.2.0 (p_extnodes.c)
