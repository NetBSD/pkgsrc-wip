$NetBSD$

Make this build if bswap32 is already defined, as for NetBSD/i586.

--- vendor/openssl-src-111.17.0+1.1.1m/openssl/crypto/aria/aria.c.orig	2025-05-19 20:01:02.477323075 +0000
+++ vendor/openssl-src-111.17.0+1.1.1m/openssl/crypto/aria/aria.c
@@ -32,9 +32,11 @@
 #define rotl32(v, r) (((uint32_t)(v) << (r)) | ((uint32_t)(v) >> (32 - r)))
 #define rotr32(v, r) (((uint32_t)(v) >> (r)) | ((uint32_t)(v) << (32 - r)))
 
+#ifndef bswap32
 #define bswap32(v)                                          \
     (((v) << 24) ^ ((v) >> 24) ^                            \
     (((v) & 0x0000ff00) << 8) ^ (((v) & 0x00ff0000) >> 8))
+#endif
 
 #define GET_U8_BE(X, Y) ((uint8_t)((X) >> ((3 - Y) * 8)))
 #define GET_U32_BE(X, Y) (                                  \
