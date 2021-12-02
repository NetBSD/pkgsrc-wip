$NetBSD$

O_PATH does not exist on NetBSD.

--- main.cc.orig	2021-11-28 04:14:07.000000000 +0000
+++ main.cc
@@ -46,6 +46,10 @@
 #error "libzip >= 1.0 is required!"
 #endif
 
+#ifndef O_PATH
+#define O_PATH 0
+#endif
+
 // Prints usage information.
 void print_usage() {
   fprintf(
