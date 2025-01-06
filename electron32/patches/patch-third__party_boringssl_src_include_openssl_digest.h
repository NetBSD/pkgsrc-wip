$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/include/openssl/digest.h.orig	2024-10-18 12:37:00.925479000 +0000
+++ third_party/boringssl/src/include/openssl/digest.h
@@ -90,6 +90,9 @@ OPENSSL_EXPORT const EVP_MD *EVP_blake2b
 // MD5 and SHA-1, as used in TLS 1.1 and below.
 OPENSSL_EXPORT const EVP_MD *EVP_md5_sha1(void);
 
+// EVP_ripemd160 is in decrepit and not available by default.
+OPENSSL_EXPORT const EVP_MD *EVP_ripemd160(void);
+
 // EVP_get_digestbynid returns an |EVP_MD| for the given NID, or NULL if no
 // such digest is known.
 OPENSSL_EXPORT const EVP_MD *EVP_get_digestbynid(int nid);
