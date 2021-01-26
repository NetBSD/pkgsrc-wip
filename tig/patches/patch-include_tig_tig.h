$NetBSD$

Macro safety fix.

--- include/tig/tig.h.orig	2020-04-08 16:17:38.000000000 +0000
+++ include/tig/tig.h
@@ -119,7 +119,7 @@
 #define MIN(x, y)	((x) < (y) ? (x) :  (y))
 #define MAX(x, y)	((x) > (y) ? (x) :  (y))
 
-#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
+#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))
 #define STRING_SIZE(x)	(sizeof(x) - 1)
 
 #define SIZEOF_STR	1024	/* Default string size. */
