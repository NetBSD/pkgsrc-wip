$NetBSD$

--- third_party/ffmpeg/libavutil/cpu.c.orig	2017-02-02 02:03:48.000000000 +0000
+++ third_party/ffmpeg/libavutil/cpu.c
@@ -25,9 +25,15 @@
 #include "common.h"
 
 #if HAVE_SCHED_GETAFFINITY
+#if defined(__NetBSD__)
+#ifndef _NETBSD_SOURCE
+# define _NETBSD_SOURCE
+#endif
+#else
 #ifndef _GNU_SOURCE
 # define _GNU_SOURCE
 #endif
+#endif
 #include <sched.h>
 #endif
 #if HAVE_GETPROCESSAFFINITYMASK || HAVE_WINRT
