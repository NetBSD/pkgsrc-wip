$NetBSD$

Add NetBSD support.

--- src/support/cdi.c.orig	2025-01-04 21:38:58.000000000 +0000
+++ src/support/cdi.c
@@ -20,6 +20,11 @@
 #ifdef __MINGW32__
 #define bswap_16(x) __builtin_bswap16(x)
 #define bswap_32(x) __builtin_bswap32(x)
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
 #else
 #include <byteswap.h>
 #endif
