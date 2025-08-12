$NetBSD$

--- spa/include/spa/utils/endian.h.orig	2025-07-23 15:42:58.000000000 +0000
+++ spa/include/spa/utils/endian.h
@@ -10,6 +10,12 @@
 #define bswap_16 bswap16
 #define bswap_32 bswap32
 #define bswap_64 bswap64
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
 #elif defined(_MSC_VER) && defined(_WIN32)
 #include <stdlib.h>
 #define __LITTLE_ENDIAN 1234
