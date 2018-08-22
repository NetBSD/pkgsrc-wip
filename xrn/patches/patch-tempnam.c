$NetBSD$

Inlcude missing system header files.

--- tempnam.c.orig	2008-11-28 19:42:06.000000000 +0000
+++ tempnam.c
@@ -7,6 +7,8 @@
 
 #include "utils.h"
 #include <sys/file.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 #ifndef P_tmpdir
 #define P_tmpdir	"/usr/tmp/"
