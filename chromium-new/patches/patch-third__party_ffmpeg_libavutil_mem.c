$NetBSD$

--- third_party/ffmpeg/libavutil/mem.c.orig	2016-06-24 01:03:40.000000000 +0000
+++ third_party/ffmpeg/libavutil/mem.c
@@ -32,7 +32,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
+#if HAVE_MALLOC_H && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
