$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/crypto/fipsmodule/digest/digests.c.orig	2024-10-18 12:37:00.617582300 +0000
+++ third_party/boringssl/src/crypto/fipsmodule/digest/digests.c
@@ -63,6 +63,7 @@
 #include <openssl/md5.h>
 #include <openssl/nid.h>
 #include <openssl/sha.h>
+#include <openssl/ripemd.h>
 
 #include "internal.h"
 #include "../delocate.h"
@@ -301,4 +302,27 @@ DEFINE_METHOD_FUNCTION(EVP_MD, EVP_md5_s
   out->ctx_size = sizeof(MD5_SHA1_CTX);
 }
 
+static void ripemd160_init(EVP_MD_CTX *ctx) {
+  CHECK(RIPEMD160_Init(ctx->md_data));
+}
+
+static void ripemd160_update(EVP_MD_CTX *ctx, const void *data, size_t count) {
+  CHECK(RIPEMD160_Update(ctx->md_data, data, count));
+}
+
+static void ripemd160_final(EVP_MD_CTX *ctx, uint8_t *md) {
+  CHECK(RIPEMD160_Final(md, ctx->md_data));
+}
+
+DEFINE_METHOD_FUNCTION(EVP_MD, EVP_ripemd160) {
+  out->type = NID_ripemd160;
+  out->md_size = RIPEMD160_DIGEST_LENGTH;
+  out->flags = 0;
+  out->init = ripemd160_init;
+  out->update = ripemd160_update;
+  out->final = ripemd160_final;
+  out->block_size = 64;
+  out->ctx_size = sizeof(RIPEMD160_CTX);
+}
+
 #undef CHECK
