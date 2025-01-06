$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_cipher.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_cipher.cc
@@ -1088,7 +1088,7 @@ void PublicKeyCipher::Cipher(const Funct
     if (EVP_PKEY_decrypt_init(ctx.get()) <= 0) {
       return ThrowCryptoError(env, ERR_get_error());
     }
-
+#ifndef OPENSSL_IS_BORINGSSL
     int rsa_pkcs1_implicit_rejection =
         EVP_PKEY_CTX_ctrl_str(ctx.get(), "rsa_pkcs1_implicit_rejection", "1");
     // From the doc -2 means that the option is not supported.
@@ -1104,6 +1104,7 @@ void PublicKeyCipher::Cipher(const Funct
           "RSA_PKCS1_PADDING is no longer supported for private decryption,"
           " this can be reverted with --security-revert=CVE-2023-46809");
     }
+#endif
   }
 
   const EVP_MD* digest = nullptr;
