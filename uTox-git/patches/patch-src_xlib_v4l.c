$NetBSD$

Use Linux headers when on Linux, not when not on OpenBSD.

--- src/xlib/v4l.c.orig	2015-12-29 21:26:38.000000000 +0000
+++ src/xlib/v4l.c
@@ -3,10 +3,10 @@
 int utox_v4l_fd = -1;
 
 #include <sys/mman.h>
-#ifdef __OpenBSD__
-#include <sys/videoio.h>
-#else
+#ifdef __linux__
 #include <linux/videodev2.h>
+#else
+#include <sys/videoio.h>
 #endif
 
 #ifndef NO_V4LCONVERT
