$NetBSD$

Avoid conflicts with SHA1_* in libssl:

 https://github.com/strophe/libstrophe/pull/59/

--- src/scram.c.orig	2015-08-18 21:07:06.000000000 +0000
+++ src/scram.c
@@ -37,9 +37,9 @@ static void SHA1(const uint8_t* data, si
                  uint8_t digest[SHA1_DIGEST_SIZE])
 {
     SHA1_CTX ctx;
-    SHA1_Init(&ctx);
-    SHA1_Update(&ctx, data, len);
-    SHA1_Final(&ctx, digest);
+    xmpp_SHA1_Init(&ctx);
+    xmpp_SHA1_Update(&ctx, data, len);
+    xmpp_SHA1_Final(&ctx, digest);
 }
 
 static void HMAC_SHA1(const uint8_t *key, size_t key_len,
@@ -66,15 +66,15 @@ static void HMAC_SHA1(const uint8_t *key
         key_opad[i] = key_pad[i] ^ opad;
     }
 
-    SHA1_Init(&ctx);
-    SHA1_Update(&ctx, key_ipad, BLOCK_SIZE);
-    SHA1_Update(&ctx, text, len);
-    SHA1_Final(&ctx, sha_digest);
-
-    SHA1_Init(&ctx);
-    SHA1_Update(&ctx, key_opad, BLOCK_SIZE);
-    SHA1_Update(&ctx, sha_digest, SHA1_DIGEST_SIZE);
-    SHA1_Final(&ctx, digest);
+    xmpp_SHA1_Init(&ctx);
+    xmpp_SHA1_Update(&ctx, key_ipad, BLOCK_SIZE);
+    xmpp_SHA1_Update(&ctx, text, len);
+    xmpp_SHA1_Final(&ctx, sha_digest);
+
+    xmpp_SHA1_Init(&ctx);
+    xmpp_SHA1_Update(&ctx, key_opad, BLOCK_SIZE);
+    xmpp_SHA1_Update(&ctx, sha_digest, SHA1_DIGEST_SIZE);
+    xmpp_SHA1_Final(&ctx, digest);
 }
 
 static void SCRAM_SHA1_Hi(const uint8_t *text, size_t len,
