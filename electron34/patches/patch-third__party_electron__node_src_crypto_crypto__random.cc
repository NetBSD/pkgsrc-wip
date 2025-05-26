$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_random.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_random.cc
@@ -140,7 +140,7 @@ Maybe<bool> RandomPrimeTraits::Additiona
 
   params->bits = bits;
   params->safe = safe;
-  params->prime.reset(BN_secure_new());
+  params->prime.reset(BN_new());
   if (!params->prime) {
     THROW_ERR_CRYPTO_OPERATION_FAILED(env, "could not generate prime");
     return Nothing<bool>();
