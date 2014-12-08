$NetBSD: patch-media_libcubeb_src_cubeb__alsa.c,v 1.2 2014/12/08 11:52:34 thomasklausner Exp $

--- media/libcubeb/src/cubeb_alsa.c.orig	2014-12-03 19:51:04.000000000 +0000
+++ media/libcubeb/src/cubeb_alsa.c
@@ -7,6 +7,9 @@
 #undef NDEBUG
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #define _XOPEN_SOURCE 500
 #include <pthread.h>
 #include <sys/time.h>
