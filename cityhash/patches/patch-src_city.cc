$NetBSD: patch-src_city.cc,v 1.1 2013/02/27 13:10:57 othyro Exp $

Add NetBSD support.

--- src/city.cc.orig	2012-10-23 06:28:36.000000000 +0000
+++ src/city.cc
@@ -60,6 +60,15 @@ static uint32 UNALIGNED_LOAD32(const cha
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
 
+#elif defined(__NetBSD__)
+
+#include <sys/types.h>
+#include <machine/bswap.h>
+#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+#endif
+
 #else
 
 #include <byteswap.h>
