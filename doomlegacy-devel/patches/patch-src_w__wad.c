$NetBSD$

Add support for UMAPINFO.

--- src/w_wad.c.orig	2023-01-10 10:38:38.711741654 +0000
+++ src/w_wad.c
@@ -118,6 +118,7 @@
 #include "d_netfil.h"
 #include "dehacked.h"
   // DEH_LoadDehackedLump
+#include "umapinfo.h"
 #include "r_defs.h"
 #include "i_system.h"
 
@@ -589,6 +590,8 @@ int W_Load_WadFile ( const char * filena
 
     GenPrintf(EMSG_info, "Added file %s (%i lumps)\n", filenamebuf, numlumps);
     W_Load_DehackedLumps( filenum );
+    // [MB] 2023-01-10: Process UMAPINFO last for highest priority
+    W_Load_UMapInfoLumps( filenum );
 
     return filenum;
 
@@ -1378,6 +1381,25 @@ void W_Load_DehackedLumps( int wadnum )
     }
 }
 
+
+// [MB] 2023-01-10: Search for all UMAPINFO lumps in all wads and load them
+void W_Load_UMapInfoLumps( int wadnum )
+{
+    lumpnum_t  clump = 0;
+
+    while (1)
+    {
+        clump = W_CheckNumForNamePwad("UMAPINFO", wadnum, LUMPNUM(clump));
+        if( ! VALID_LUMP(clump) )
+            break;
+        GenPrintf(EMSG_info, "Loading UMAPINFO from %s\n",
+                  wadfiles[wadnum]->filename);
+        UMI_LoadUMapInfoLump(clump);
+        clump++;
+    }
+}
+
+
 // [WDJ] Return a sum unique to a lump, to detect replacements.
 // The lumpptr must be to a Z_Malloc lump.
 uint64_t  W_lump_checksum( void* lumpptr )
