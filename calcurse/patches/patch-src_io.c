$NetBSD$

--- src/io.c.orig	2017-01-12 07:38:27.000000000 +0000
+++ src/io.c
@@ -34,6 +34,7 @@
  *
  */
 
+#include <stdarg.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
