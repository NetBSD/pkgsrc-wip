$NetBSD$

# Add OpenBSD and SunOS support

--- include/unaligned.h.orig	2025-01-08 15:33:59.000000000 +0000
+++ include/unaligned.h
@@ -40,11 +40,21 @@
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
 #define isal_bswap32(x) OSSwapInt32(x)
 #define isal_bswap64(x) OSSwapInt64(x)
+#elif defined(__sun)
+#define isal_bswap16(x) __builtin_bswap16(x)
+#define isal_bswap32(x) __builtin_bswap32(x)
+#define isal_bswap64(x) __builtin_bswap64(x)
 #elif defined(__GNUC__) && !defined(__MINGW32__)
 #include <byteswap.h>
 #define isal_bswap16(x) bswap_16(x)
