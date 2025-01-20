$NetBSD$

# Use standard compiler macros

--- long-hashtable.c.orig	2024-07-25 00:30:10.000000000 +0000
+++ long-hashtable.c
@@ -21,8 +21,8 @@
 #include <stdlib.h>
 #include <string.h>
 
-#ifndef MACOS
-#ifndef FREEBSD
+#ifndef __APPLE__
+#ifndef __FreeBSD__
 #include <malloc.h>
 #endif
 #endif
