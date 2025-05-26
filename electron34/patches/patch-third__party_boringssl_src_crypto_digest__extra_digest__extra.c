$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/crypto/digest_extra/digest_extra.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/boringssl/src/crypto/digest_extra/digest_extra.c
@@ -87,6 +87,7 @@ static const struct nid_to_digest nid_to
     {NID_sha512, EVP_sha512, SN_sha512, LN_sha512},
     {NID_sha512_256, EVP_sha512_256, SN_sha512_256, LN_sha512_256},
     {NID_md5_sha1, EVP_md5_sha1, SN_md5_sha1, LN_md5_sha1},
+    {NID_ripemd160, EVP_ripemd160, SN_ripemd160, LN_ripemd160},
     // As a remnant of signing |EVP_MD|s, OpenSSL returned the corresponding
     // hash function when given a signature OID. To avoid unintended lax parsing
     // of hash OIDs, this is no longer supported for lookup by OID or NID.
