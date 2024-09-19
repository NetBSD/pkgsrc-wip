$NetBSD$

# Use predefined macros

--- long-hashtable.c.orig	2021-03-31 00:35:27.202818216 +0000
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
