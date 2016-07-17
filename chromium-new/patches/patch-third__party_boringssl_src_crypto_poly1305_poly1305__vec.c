$NetBSD$

--- third_party/boringssl/src/crypto/poly1305/poly1305_vec.c.orig	2016-06-24 01:03:30.000000000 +0000
+++ third_party/boringssl/src/crypto/poly1305/poly1305_vec.c
@@ -22,6 +22,11 @@
 
 #include "../internal.h"
 
+#if defined(__NetBSD__)
+#define ALIGN(x) __attribute__((aligned(x)))
+#else
+#define ALIGN(x) alignas(x)
+#endif
 
 #if !defined(OPENSSL_WINDOWS) && defined(OPENSSL_X86_64)
 
@@ -33,10 +38,10 @@
 
 typedef __m128i xmmi;
 
-static const alignas(16) uint32_t poly1305_x64_sse2_message_mask[4] = {
+static const ALIGN(16) uint32_t poly1305_x64_sse2_message_mask[4] = {
     (1 << 26) - 1, 0, (1 << 26) - 1, 0};
-static const alignas(16) uint32_t poly1305_x64_sse2_5[4] = {5, 0, 5, 0};
-static const alignas(16) uint32_t poly1305_x64_sse2_1shl128[4] = {
+static const ALIGN(16) uint32_t poly1305_x64_sse2_5[4] = {5, 0, 5, 0};
+static const ALIGN(16) uint32_t poly1305_x64_sse2_1shl128[4] = {
     (1 << 24), 0, (1 << 24), 0};
 
 static inline uint128_t add128(uint128_t a, uint128_t b) { return a + b; }
