$NetBSD$

--- src/lispbibl.d.orig	2019-11-03 21:40:38.000000000 +0000
+++ src/lispbibl.d
@@ -2427,7 +2427,7 @@ typedef enum {
        There is room from 0x09000000UL to 0xBB000000UL, but let's keep some
        distance. */
     #define MAPPABLE_ADDRESS_RANGE_START 0x10000000UL
-    #define MAPPABLE_ADDRESS_RANGE_END   0xAFFFFFFFUL
+    #define MAPPABLE_ADDRESS_RANGE_END   0x9FFFFFFFUL
   #endif
   #if defined(UNIX_NETBSD) && defined(SPARC)
     /* On NetBSD/sparc:
