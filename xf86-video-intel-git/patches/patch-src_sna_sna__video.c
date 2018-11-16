$NetBSD$

--- src/sna/sna_video.c.orig	2018-11-15 07:16:49.675406775 +0000
+++ src/sna/sna_video.c
@@ -59,7 +59,13 @@
 #include "intel_options.h"
 
 #include <xf86xv.h>
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define bswap_32 bswap32
+#else
 #include <byteswap.h>
+#endif
 
 #ifdef SNA_XVMC
 #define _SNA_XVMC_SERVER_
