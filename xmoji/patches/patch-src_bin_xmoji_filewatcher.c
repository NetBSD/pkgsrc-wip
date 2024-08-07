$NetBSD$

--- src/bin/xmoji/filewatcher.c.orig	2024-08-07 16:43:16.520801223 +0000
+++ src/bin/xmoji/filewatcher.c
@@ -17,6 +17,9 @@
 #    define _BSD_SOURCE
 #  endif
 #endif
+#ifdef __NetBSD__
+#define statfs statvfs
+#endif
 
 #include "filewatcher.h"
 
