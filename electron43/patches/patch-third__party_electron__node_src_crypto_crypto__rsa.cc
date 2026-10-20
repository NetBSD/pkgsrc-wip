$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/src/crypto/crypto_rsa.cc.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_rsa.cc
@@ -12,6 +12,30 @@
 #include <openssl/bn.h>
 #include <openssl/rsa.h>
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER <0x1010105fL
+struct rsa_st {
+  int pad;
+  int32_t version;
+  void *meth;
+  void *engine;
+  void *n;
+  void *e;
+  void *d;
+  void *p;
+  void *q;
+  void *dmp1;
+  void *dmq1;
+  void *iqmp;
+  void *prime_infos;
+  RSA_PSS_PARAMS *pss;
+};
+
+static const RSA_PSS_PARAMS *RSA_get0_pss_params(const RSA *r)
+{
+  return r->pss;
+}
+#endif
+
 namespace node {
 
 using ncrypto::BignumPointer;
