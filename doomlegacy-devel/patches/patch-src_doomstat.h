$NetBSD$

Add support for UMAPINFO.

--- src/doomstat.h.orig	2023-01-22 09:51:41.258749604 +0000
+++ src/doomstat.h
@@ -75,6 +75,9 @@
 #include "d_player.h"
 #include "d_clisrv.h"
 
+// [MB] 2023-01-22: Support for UMAPINFO added
+#include "umapinfo.h"
+
 
 // Game mode handling - identify IWAD version,
 //  handle IWAD dependend animations etc.
@@ -234,6 +237,11 @@ extern  skill_e         gameskill;	// ea
 extern  byte            gameepisode;	// Doom episode, 1..4
 extern  byte            gamemap;	// level 1..32
 
+// [MB] 2023-01-22: Support for UMAPINFO added
+// If this pointer is NULL, no additional UMAPINFO data is available
+// Otherwise it points to a UMAPINFO map entry structure
+extern  mapentry_t    * gamemapinfo;
+
 // Nightmare mode flag, single player.
 // extern  boolean         respawnmonsters;
 
