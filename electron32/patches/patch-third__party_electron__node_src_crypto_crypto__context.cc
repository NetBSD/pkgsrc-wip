$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_context.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_context.cc
@@ -63,7 +63,7 @@ inline X509_STORE* GetOrCreateRootCertSt
 // Caller responsible for BIO_free_all-ing the returned object.
 BIOPointer LoadBIO(Environment* env, Local<Value> v) {
   if (v->IsString() || v->IsArrayBufferView()) {
-    BIOPointer bio(BIO_new(BIO_s_secmem()));
+    BIOPointer bio(BIO_new(BIO_s_mem()));
     if (!bio) return nullptr;
     ByteSource bsrc = ByteSource::FromStringOrBuffer(env, v);
     if (bsrc.size() > INT_MAX) return nullptr;
@@ -882,10 +882,12 @@ void SecureContext::SetDHParam(const Fun
   // If the user specified "auto" for dhparams, the JavaScript layer will pass
   // true to this function instead of the original string. Any other string
   // value will be interpreted as custom DH parameters below.
+#ifndef OPENSSL_IS_BORINGSSL
   if (args[0]->IsTrue()) {
     CHECK(SSL_CTX_set_dh_auto(sc->ctx_.get(), true));
     return;
   }
+#endif
 
   DHPointer dh;
   {
