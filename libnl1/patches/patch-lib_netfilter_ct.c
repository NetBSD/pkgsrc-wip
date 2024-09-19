$NetBSD$

- Use more standard bswap_64() since __bswap_64() is not supported on
  musl-libc.

--- lib/netfilter/ct.c.orig	2021-08-07 09:04:22.926000000 +0000
+++ lib/netfilter/ct.c
@@ -37,7 +37,7 @@ static uint64_t ntohll(uint64_t x)
 #elif __BYTE_ORDER == __LITTLE_ENDIAN
 static uint64_t ntohll(uint64_t x)
 {
-	return __bswap_64(x);
+	return bswap_64(x);
 }
 #endif
 
