$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_dsa.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_dsa.cc
@@ -40,7 +40,7 @@ namespace crypto {
 EVPKeyCtxPointer DsaKeyGenTraits::Setup(DsaKeyPairGenConfig* params) {
   EVPKeyCtxPointer param_ctx(EVP_PKEY_CTX_new_id(EVP_PKEY_DSA, nullptr));
   EVP_PKEY* raw_params = nullptr;
-
+#ifndef OPENSSL_IS_BORINGSSL
   if (!param_ctx ||
       EVP_PKEY_paramgen_init(param_ctx.get()) <= 0 ||
       EVP_PKEY_CTX_set_dsa_paramgen_bits(
@@ -55,7 +55,9 @@ EVPKeyCtxPointer DsaKeyGenTraits::Setup(
       return EVPKeyCtxPointer();
     }
   }
-
+#else
+  return EVPKeyCtxPointer();
+#endif
   if (EVP_PKEY_paramgen(param_ctx.get(), &raw_params) <= 0)
     return EVPKeyCtxPointer();
 
