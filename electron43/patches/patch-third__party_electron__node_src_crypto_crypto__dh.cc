$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_dh.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_dh.cc
@@ -154,13 +154,11 @@ bool DiffieHellman::Init(BignumPointer&&
 bool DiffieHellman::Init(const char* p, int p_len, int g) {
   dh_.reset(DH_new());
   if (p_len <= 0) {
-    ERR_put_error(ERR_LIB_BN, BN_F_BN_GENERATE_PRIME_EX,
-      BN_R_BITS_TOO_SMALL, __FILE__, __LINE__);
+    OPENSSL_PUT_ERROR(BN, BN_R_BITS_TOO_SMALL);
     return false;
   }
   if (g <= 1) {
-    ERR_put_error(ERR_LIB_DH, DH_F_DH_BUILTIN_GENPARAMS,
-      DH_R_BAD_GENERATOR, __FILE__, __LINE__);
+    OPENSSL_PUT_ERROR(DH, DH_R_BAD_GENERATOR);
     return false;
   }
   BignumPointer bn_p(
@@ -176,20 +174,17 @@ bool DiffieHellman::Init(const char* p, 
 bool DiffieHellman::Init(const char* p, int p_len, const char* g, int g_len) {
   dh_.reset(DH_new());
   if (p_len <= 0) {
-    ERR_put_error(ERR_LIB_BN, BN_F_BN_GENERATE_PRIME_EX,
-      BN_R_BITS_TOO_SMALL, __FILE__, __LINE__);
+    OPENSSL_PUT_ERROR(BN, BN_R_BITS_TOO_SMALL);
     return false;
   }
   if (g_len <= 0) {
-    ERR_put_error(ERR_LIB_DH, DH_F_DH_BUILTIN_GENPARAMS,
-      DH_R_BAD_GENERATOR, __FILE__, __LINE__);
+    OPENSSL_PUT_ERROR(DH, DH_R_BAD_GENERATOR);
     return false;
   }
   BignumPointer bn_g(
       BN_bin2bn(reinterpret_cast<const unsigned char*>(g), g_len, nullptr));
   if (BN_is_zero(bn_g.get()) || BN_is_one(bn_g.get())) {
-    ERR_put_error(ERR_LIB_DH, DH_F_DH_BUILTIN_GENPARAMS,
-      DH_R_BAD_GENERATOR, __FILE__, __LINE__);
+    OPENSSL_PUT_ERROR(DH, DH_R_BAD_GENERATOR);
     return false;
   }
   BignumPointer bn_p(
@@ -219,8 +214,10 @@ typedef BignumPointer (*StandardizedGrou
 inline StandardizedGroupInstantiator FindDiffieHellmanGroup(const char* name) {
 #define V(n, p)                                                                \
   if (StringEqualNoCase(name, n)) return InstantiateStandardizedGroup<p>
+#ifndef OPENSSL_IS_BORINGSSL
   V("modp1", BN_get_rfc2409_prime_768);
   V("modp2", BN_get_rfc2409_prime_1024);
+#endif
   V("modp5", BN_get_rfc3526_prime_1536);
   V("modp14", BN_get_rfc3526_prime_2048);
   V("modp15", BN_get_rfc3526_prime_3072);
@@ -565,9 +562,11 @@ EVPKeyCtxPointer DhKeyGenTraits::Setup(D
     key_params = EVPKeyPointer(EVP_PKEY_new());
     CHECK(key_params);
     CHECK_EQ(EVP_PKEY_assign_DH(key_params.get(), dh.release()), 1);
-  } else if (int* prime_size = std::get_if<int>(&params->params.prime)) {
+  } else if (std::get_if<int>(&params->params.prime)) {
     EVPKeyCtxPointer param_ctx(EVP_PKEY_CTX_new_id(EVP_PKEY_DH, nullptr));
     EVP_PKEY* raw_params = nullptr;
+#ifndef OPENSSL_IS_BORINGSSL
+    int* prime_size = std::get_if<int>(&params->params.prime);
     if (!param_ctx ||
         EVP_PKEY_paramgen_init(param_ctx.get()) <= 0 ||
         EVP_PKEY_CTX_set_dh_paramgen_prime_len(
@@ -581,6 +580,9 @@ EVPKeyCtxPointer DhKeyGenTraits::Setup(D
     }
 
     key_params = EVPKeyPointer(raw_params);
+#else
+    return EVPKeyCtxPointer();
+#endif
   } else {
     UNREACHABLE();
   }
