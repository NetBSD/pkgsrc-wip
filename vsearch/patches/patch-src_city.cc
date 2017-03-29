$NetBSD$

# Handle non-standardized swap macros

--- src/city.cc.orig	2016-01-25 19:23:36 UTC
+++ src/city.cc
@@ -69,6 +69,13 @@ static uint32 UNALIGNED_LOAD32(const cha
 #define bswap_64(x) bswap64(x)
 #endif
 
+#elif defined(__FreeBSD__)
+
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
+#include <sys/endian.h>
+
 #else
 
 #include <byteswap.h>
