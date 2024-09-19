$NetBSD: patch-hw_xfree86_os-support_bsd_i386__video.c,v 1.1 2015/04/25 11:47:03 tnn Exp $

Added patch from FreeBSD ports / DragonFly dports

--- hw/xfree86/os-support/bsd/i386_video.c.orig	2015-01-17 23:42:52.000000000 +0000
+++ hw/xfree86/os-support/bsd/i386_video.c
@@ -32,6 +32,9 @@
 #include "xf86Priv.h"
 
 #include <errno.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/types.h>
+#endif
 #include <sys/mman.h>
 
 #include "xf86_OSlib.h"
@@ -42,6 +45,9 @@
 #else
 #define MAP_FLAGS (MAP_FILE | MAP_SHARED)
 #endif
+#if defined(__NetBSD__) && defined(USE_AMD64_IOPL)
+#define amd64_iopl x86_64_iopl
+#endif
 
 #ifdef __OpenBSD__
 #define SYSCTL_MSG "\tCheck that you have set 'machdep.allowaperture=1'\n"\
