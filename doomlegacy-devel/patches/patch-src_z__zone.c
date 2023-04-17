$NetBSD$

Use heap of OS instead of Doom zone memory.

--- src/z_zone.c.orig	2023-02-10 15:51:01.000000000 +0000
+++ src/z_zone.c
@@ -100,7 +100,7 @@
 // When the user writes out-of-bounds of malloced region it will do a sigsegv.
 // It does not use the tags, cannot recover PU_CACHE, PU_LEVEL, etc. memory.
 // Uses the most memory of all choices.
-//#define PLAIN_MALLOC
+#define PLAIN_MALLOC
 
 // [WDJ] Combination of malloc and tags.
 // Does malloc from heap, so will grow from heap as use increases.
@@ -112,13 +112,13 @@
 // allocations from it.
 // Has a command line option to set the zone block size ( -mb <int> ).
 // It also has some conditional experimental code.
-#define ZONE_ZALLOC
+//#define ZONE_ZALLOC
 
 // Grows the initial allocation block when it runs out of memory.
 // Runs in the smallest memory of all the choices.
 // Uses tags, and recovers PU_CACHE and PU_LEVEL memory first.
 // Applied as an option to ZONE_ZALLOC.
-#define GROW_ZONE
+//#define GROW_ZONE
 
 // Aggressively purges any PU_CACHE, clearing cache faster.
 // This stresses the memory system more, testing user code to not
