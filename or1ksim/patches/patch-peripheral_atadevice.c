$NetBSD: patch-peripheral_atadevice.c,v 1.1 2013/10/14 13:00:08 ryo-on Exp $

--- peripheral/atadevice.c.orig	2011-04-08 10:59:34.000000000 +0000
+++ peripheral/atadevice.c
@@ -35,6 +35,10 @@
 #define bswap_16(x) OSSwapInt16(x)
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define bswap_16 bswap16
 #else
 #include <byteswap.h>
 #endif
