$NetBSD$

https://github.com/Zirias/xmoji/pull/6

--- src/bin/xmoji/filewatcher.c.orig	2024-08-12 16:29:36.000000000 +0000
+++ src/bin/xmoji/filewatcher.c
@@ -1,4 +1,6 @@
+#ifdef __linux__
 #define _POSIX_C_SOURCE 200809L
+#endif
 
 /* Feature test hack ahead!
  *
@@ -17,6 +19,9 @@
 #    define _BSD_SOURCE
 #  endif
 #endif
+#ifdef __NetBSD__
+#define statfs statvfs
+#endif
 
 #include "filewatcher.h"
 
