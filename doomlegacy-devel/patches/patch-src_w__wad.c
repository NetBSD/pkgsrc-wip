$NetBSD$

Add support for UMAPINFO.

--- src/w_wad.c.orig	2023-02-10 15:51:01.000000000 +0000
+++ src/w_wad.c
@@ -109,6 +109,9 @@
 #include <unistd.h>
   // close, read, lseek
 
+// [MB] 2023-03-19: Support for UMAPINFO added
+#include "doomstat.h"
+
 #include "doomincl.h"
 #include "w_wad.h"
 #include "z_zone.h"
@@ -589,6 +592,12 @@ int W_Load_WadFile ( const char * filena
 
     GenPrintf(EMSG_info, "Added file %s (%i lumps)\n", filenamebuf, numlumps);
     W_Load_DehackedLumps( filenum );
+    // [MB] 2023-01-10: Process UMAPINFO last for highest priority
+    if ( EN_doom_etc )
+    {
+        // UMAPINFO is for Doom only (not suitable for Heretic and Hexen)
+        W_Load_UMapInfoLumps( filenum );
+    }
 
     return filenum;
 
@@ -1378,6 +1387,25 @@ void W_Load_DehackedLumps( int wadnum )
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
