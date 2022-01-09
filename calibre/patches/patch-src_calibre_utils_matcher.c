$NetBSD$

At least for gcc 7.5 and 8.

--- src/calibre/utils/matcher.c.orig	2020-02-21 03:27:12.000000000 +0000
+++ src/calibre/utils/matcher.c
@@ -15,7 +15,7 @@
 #define inline
 #endif
 
-typedef unsigned char bool;
+//typedef unsigned char bool;
 #define TRUE 1
 #define FALSE 0
 #define MAX(x, y) ((x > y) ? x : y)
