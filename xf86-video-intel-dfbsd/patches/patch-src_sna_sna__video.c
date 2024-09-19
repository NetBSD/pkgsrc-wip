$NetBSD$

Extend to DragonFly

2019-01-10
sna: fix of byteswap.h absence on bsd

https://cgit.freedesktop.org/xorg/driver/xf86-video-intel/commit/?id=985553dff9d9de255edb6acb0ae85117ceb3e76c

--- src/sna/sna_video.c.orig	2019-01-10 10:01:58.000000000 +0000
+++ src/sna/sna_video.c
@@ -59,7 +59,7 @@
 #include "intel_options.h"
 
 #include <xf86xv.h>
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <sys/endian.h>
 #ifdef __OpenBSD__
