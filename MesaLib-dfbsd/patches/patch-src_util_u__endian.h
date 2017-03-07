$NetBSD$

From FreeBSD ports graphics/libGL mesa 13.0.5.

--- src/util/u_endian.h.orig	2017-02-13 11:55:50.000000000 +0000
+++ src/util/u_endian.h
@@ -54,7 +54,7 @@
 # define PIPE_ARCH_BIG_ENDIAN
 #endif
 
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <machine/endian.h>
 
