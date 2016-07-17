$NetBSD$

--- third_party/ffmpeg/libavutil/cpu.c.orig	2016-06-24 01:03:40.000000000 +0000
+++ third_party/ffmpeg/libavutil/cpu.c
@@ -24,6 +24,9 @@
 #include "opt.h"
 #include "common.h"
 
+/* TODO(rene) work around a compile error with GCC 4.6.4 on FreeBSD */
+#define __BSD_VISIBLE 1
+
 #if HAVE_SCHED_GETAFFINITY
 #ifndef _GNU_SOURCE
 # define _GNU_SOURCE
