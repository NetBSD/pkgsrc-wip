$NetBSD$

Avoid conflicts with SHA1_* in libssl:

 https://github.com/strophe/libstrophe/pull/59/

--- src/sha1.h.orig	2015-08-18 21:07:06.000000000 +0000
+++ src/sha1.h
@@ -23,9 +23,9 @@ typedef struct {
 
 #define SHA1_DIGEST_SIZE 20
 
-void SHA1_Init(SHA1_CTX* context);
-void SHA1_Update(SHA1_CTX* context, const uint8_t* data, const size_t len);
-void SHA1_Final(SHA1_CTX* context, uint8_t digest[SHA1_DIGEST_SIZE]);
+void xmpp_SHA1_Init(SHA1_CTX* context);
+void xmpp_SHA1_Update(SHA1_CTX* context, const uint8_t* data, const size_t len);
+void xmpp_SHA1_Final(SHA1_CTX* context, uint8_t digest[SHA1_DIGEST_SIZE]);
 
 #ifdef __cplusplus
 }
