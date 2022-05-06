$NetBSD$

--- util-src/pposix.c.orig	2022-03-08 12:34:39.594708341 +0000
+++ util-src/pposix.c
@@ -38,6 +38,7 @@
 #endif
 #endif
 
+#include <unistd.h>
 #include <stdlib.h>
 #include <math.h>
 #include <unistd.h>
