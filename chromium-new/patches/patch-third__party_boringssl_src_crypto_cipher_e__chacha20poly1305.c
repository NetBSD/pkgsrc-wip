$NetBSD$

--- third_party/boringssl/src/crypto/cipher/e_chacha20poly1305.c.orig	2016-06-24 01:03:30.000000000 +0000
+++ third_party/boringssl/src/crypto/cipher/e_chacha20poly1305.c
@@ -93,7 +93,11 @@ static void aead_poly1305(aead_poly1305_
                           const uint8_t nonce[12], const uint8_t *ad,
                           size_t ad_len, const uint8_t *ciphertext,
                           size_t ciphertext_len) {
+#if defined(__NetBSD__)
+  uint8_t poly1305_key[32] __attribute__((aligned(16)));
+#else
   alignas(16) uint8_t poly1305_key[32];
+#endif
   memset(poly1305_key, 0, sizeof(poly1305_key));
   CRYPTO_chacha_20(poly1305_key, poly1305_key, sizeof(poly1305_key),
                    c20_ctx->key, nonce, 0);
@@ -134,7 +138,11 @@ static int seal_impl(aead_poly1305_updat
 
   CRYPTO_chacha_20(out, in, in_len, c20_ctx->key, nonce, 1);
 
+#if defined(__NetBSD__)
+  uint8_t tag[POLY1305_TAG_LEN] __attribute__((aligned(16)));
+#else
   alignas(16) uint8_t tag[POLY1305_TAG_LEN];
+#endif
   aead_poly1305(poly1305_update, tag, c20_ctx, nonce, ad, ad_len, out, in_len);
 
   memcpy(out + in_len, tag, c20_ctx->tag_len);
@@ -168,7 +176,11 @@ static int open_impl(aead_poly1305_updat
   }
 
   plaintext_len = in_len - c20_ctx->tag_len;
+#if defined(__NetBSD__)
+  uint8_t tag[POLY1305_TAG_LEN] __attribute__((aligned(16)));
+#else
   alignas(16) uint8_t tag[POLY1305_TAG_LEN];
+#endif
   aead_poly1305(poly1305_update, tag, c20_ctx, nonce, ad, ad_len, in,
                 plaintext_len);
   if (CRYPTO_memcmp(tag, in + plaintext_len, c20_ctx->tag_len) != 0) {
