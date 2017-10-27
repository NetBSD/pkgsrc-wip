$NetBSD$

--- include/tig/tig.h.orig	2017-09-29 15:15:26.000000000 +0000
+++ include/tig/tig.h
@@ -108,7 +108,7 @@
 #define MIN(x, y)	((x) < (y) ? (x) :  (y))
 #define MAX(x, y)	((x) > (y) ? (x) :  (y))
 
-#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
+#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))
 #define STRING_SIZE(x)	(sizeof(x) - 1)
 
 #define SIZEOF_STR	1024	/* Default string size. */
