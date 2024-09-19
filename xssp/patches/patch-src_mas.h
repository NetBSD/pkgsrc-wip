$NetBSD$

# Fix collision

--- src/mas.h.orig	2018-07-24 16:34:10 UTC
+++ src/mas.h
@@ -40,9 +40,9 @@ typedef uint32_t  uint32;
 typedef int64_t    int64;
 typedef uint64_t  uint64;
 
-#ifndef nullptr
-#define nullptr NULL
-#endif
+//#ifndef nullptr
+//#define nullptr NULL
+//#endif
 
 // we even have globals:
 extern int VERBOSE;
