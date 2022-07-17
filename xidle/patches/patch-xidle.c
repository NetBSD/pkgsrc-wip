$NetBSD$

Define non-standard compiler attribute extension.
Do not hard-code xlock path.

--- xidle.c.orig	2015-05-26 05:22:15.000000000 +0000
+++ xidle.c
@@ -43,9 +43,12 @@
 #endif
 
 #ifndef PATH_PROG
-#define PATH_PROG	"/usr/X11R6/bin/xlock"
+#define PATH_PROG	"@PREFIX@/bin/xlock"
 #endif
 
+#ifndef	__dead 
+#define __dead      __attribute__((__noreturn__))
+#endif
 
 enum {
 	north = 0x01,
