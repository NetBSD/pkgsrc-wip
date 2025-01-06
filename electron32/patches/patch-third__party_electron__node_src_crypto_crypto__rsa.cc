$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_rsa.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_rsa.cc
@@ -616,10 +616,11 @@ Maybe<bool> GetRsaKeyDetail(
       }
 
       if (params->saltLength != nullptr) {
-        if (ASN1_INTEGER_get_int64(&salt_length, params->saltLength) != 1) {
-          ThrowCryptoError(env, ERR_get_error(), "ASN1_INTEGER_get_in64 error");
-          return Nothing<bool>();
-        }
+        // TODO(codebytere): Upstream a shim to BoringSSL?
+        // if (ASN1_INTEGER_get_int64(&salt_length, params->saltLength) != 1) {
+        //   ThrowCryptoError(env, ERR_get_error(), "ASN1_INTEGER_get_in64 error");
+        //   return Nothing<bool>();
+        // }
       }
 
       if (target
