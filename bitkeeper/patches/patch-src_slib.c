$NetBSD$

--- src/slib.c.orig	2016-07-15 19:21:30.000000000 +0000
+++ src/slib.c
@@ -14888,7 +14888,7 @@ printTagDetails(sccs *s, ser_t d, symbol
  * Makefile).
  */
 extern	struct kwval *kw2val_lookup(register const char *str,
-    register unsigned int len);
+    register size_t len);
 #include "kw2val_lookup.c"
 
 #define	notKeyword -1
