$NetBSD: patch-hw_xfree86_os-support_bsd_i386__video.c,v 1.2 2023/03/30 08:25:06 wiz Exp $

Use correct symbol and amd64.

--- hw/xfree86/os-support/bsd/i386_video.c.orig	2026-08-20 01:02:10.000000000 +0000
+++ hw/xfree86/os-support/bsd/i386_video.c
@@ -45,6 +45,9 @@
 #else
 #define MAP_FLAGS (MAP_FILE | MAP_SHARED)
 #endif
+#if defined(__NetBSD__) && defined(USE_AMD64_IOPL)
+#define amd64_iopl x86_64_iopl
+#endif
 
 #ifndef CONSOLE_X_TV_ON
 #define CONSOLE_X_TV_ON _IOW('t',155,int)
