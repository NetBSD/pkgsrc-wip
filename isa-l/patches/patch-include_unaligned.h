$NetBSD$

# Add OpenBSD support

--- include/unaligned.h.orig	2025-06-01 20:07:29.780618759 +0000
+++ include/unaligned.h
@@ -40,6 +40,12 @@
 #define isal_bswap16(x) bswap16(x)
 #define isal_bswap32(x) bswap32(x)
 #define isal_bswap64(x) bswap64(x)
+#elif defined(__OpenBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define isal_bswap16(x) swap16(x)
+#define isal_bswap32(x) swap32(x)
+#define isal_bswap64(x) swap64(x)
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
 #define isal_bswap16(x) OSSwapInt16(x)
