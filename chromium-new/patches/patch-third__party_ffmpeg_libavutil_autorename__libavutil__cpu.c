$NetBSD$

--- third_party/ffmpeg/libavutil/autorename_libavutil_cpu.c.orig	2016-06-24 01:03:40.000000000 +0000
+++ third_party/ffmpeg/libavutil/autorename_libavutil_cpu.c
@@ -24,6 +24,12 @@
 #include "opt.h"
 #include "common.h"
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE 1
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #if HAVE_SCHED_GETAFFINITY
 #ifndef _GNU_SOURCE
 # define _GNU_SOURCE
@@ -34,6 +40,7 @@
 #include <windows.h>
 #endif
 #if HAVE_SYSCTL
+#define __BSD_VISIBLE 1
 #if HAVE_SYS_PARAM_H
 #include <sys/param.h>
 #endif
