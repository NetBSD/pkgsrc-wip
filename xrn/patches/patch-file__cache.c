$NetBSD$

Inlcude missing system header file.

--- file_cache.c.orig	2008-11-28 19:42:06.000000000 +0000
+++ file_cache.c
@@ -2,6 +2,7 @@
   A file cache implementation.
   */
 
+#include <unistd.h>
 #include <assert.h>
 
 #ifdef XRN
