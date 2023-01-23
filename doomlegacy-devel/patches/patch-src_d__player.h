$NetBSD$

Add support for UMAPINFO.

--- src/d_player.h.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/d_player.h
@@ -63,6 +63,10 @@
 
 #include "b_bot.h"	//added by AC for acbot
 
+// [MB] 2023-01-22: Support for UMAPINFO added
+#include "umapinfo.h"
+
+
 //
 // Player states.
 //
@@ -266,6 +270,11 @@ typedef struct
     int         lev_prev;
     int         lev_next;
 
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    int         epsd_next;     // Progression may cross into another episode
+    mapentry_t  *lastmapinfo;
+    mapentry_t  *nextmapinfo;
+
     int         maxkills;
     int         maxitems;
     int         maxsecret;
