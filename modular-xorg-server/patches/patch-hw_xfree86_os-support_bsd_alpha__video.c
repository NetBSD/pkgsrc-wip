$NetBSD: patch-hw_xfree86_os-support_bsd_alpha__video.c,v 1.1 2021/07/21 21:50:29 tnn Exp $

Fix build on NetBSD/alpha. From xsrc.

--- hw/xfree86/os-support/bsd/alpha_video.c.orig	2026-08-20 01:02:10.000000000 +0000
+++ hw/xfree86/os-support/bsd/alpha_video.c
@@ -37,6 +37,9 @@
 
 #ifndef __NetBSD__
 #include <sys/sysctl.h>
+#else
+#include <machine/sysarch.h>
+#include <machine/pio.h>
 #endif
 
 #include "xf86_OSlib.h"
