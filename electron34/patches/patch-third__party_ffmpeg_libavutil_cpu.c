$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/ffmpeg/libavutil/cpu.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/ffmpeg/libavutil/cpu.c
@@ -38,10 +38,7 @@
 #if HAVE_GETPROCESSAFFINITYMASK || HAVE_WINRT
 #include <windows.h>
 #endif
-#if HAVE_SYSCTL
-#if HAVE_SYS_PARAM_H
-#include <sys/param.h>
-#endif
+#if HAVE_SYSCTL && !defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
