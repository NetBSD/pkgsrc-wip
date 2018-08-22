$NetBSD$

Inlcude missing system header file.

--- news.h.orig	2008-11-28 19:48:24.000000000 +0000
+++ news.h
@@ -35,6 +35,7 @@
  *
  */
 
+#include <stdlib.h>
 #include "avl.h"
 #include "hash.h"
 #include "file_cache.h"
