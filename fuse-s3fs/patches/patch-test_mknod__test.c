$NetBSD$

--- test/mknod_test.c	2023-11-05 16:35:57.703118419 +0000
+++ test/mknod_test.c
@@ -27,9 +27,6 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
-#ifndef __APPLE__
-#include <sys/sysmacros.h>
-#endif
 
 //---------------------------------------------------------
 // Const
