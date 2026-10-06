$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_common.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_common.cc
@@ -158,7 +158,7 @@ const char* GetClientHelloALPN(const SSL
   const unsigned char* buf;
   size_t len;
   size_t rem;
-
+#ifndef OPENSSL_IS_BORINGSSL
   if (!SSL_client_hello_get0_ext(
           ssl.get(),
           TLSEXT_TYPE_application_layer_protocol_negotiation,
@@ -171,13 +171,15 @@ const char* GetClientHelloALPN(const SSL
   len = (buf[0] << 8) | buf[1];
   if (len + 2 != rem) return nullptr;
   return reinterpret_cast<const char*>(buf + 3);
+#endif
+  return nullptr;
 }
 
 const char* GetClientHelloServerName(const SSLPointer& ssl) {
   const unsigned char* buf;
   size_t len;
   size_t rem;
-
+#ifndef OPENSSL_IS_BORINGSSL
   if (!SSL_client_hello_get0_ext(
           ssl.get(),
           TLSEXT_TYPE_server_name,
@@ -199,6 +201,8 @@ const char* GetClientHelloServerName(con
   if (len + 2 > rem)
     return nullptr;
   return reinterpret_cast<const char*>(buf + 5);
+#endif
+  return nullptr;
 }
 
 const char* GetServerName(SSL* ssl) {
@@ -1036,14 +1040,14 @@ MaybeLocal<Array> GetClientHelloCiphers(
     Environment* env,
     const SSLPointer& ssl) {
   EscapableHandleScope scope(env->isolate());
-  const unsigned char* buf;
-  size_t len = SSL_client_hello_get0_ciphers(ssl.get(), &buf);
+  // const unsigned char* buf = nullptr;
+  size_t len = 0; // SSL_client_hello_get0_ciphers(ssl.get(), &buf);
   size_t count = len / 2;
   MaybeStackBuffer<Local<Value>, 16> ciphers(count);
   int j = 0;
   for (size_t n = 0; n < len; n += 2) {
-    const SSL_CIPHER* cipher = SSL_CIPHER_find(ssl.get(), buf);
-    buf += 2;
+    const SSL_CIPHER* cipher = nullptr; // SSL_CIPHER_find(ssl.get(), buf);
+    // buf += 2;
     Local<Object> obj = Object::New(env->isolate());
     if (!Set(env->context(),
              obj,
@@ -1096,8 +1100,11 @@ MaybeLocal<Object> GetEphemeralKey(Envir
 
   EscapableHandleScope scope(env->isolate());
   Local<Object> info = Object::New(env->isolate());
+#ifndef OPENSSL_IS_BORINGSSL
   if (!SSL_get_peer_tmp_key(ssl.get(), &raw_key)) return scope.Escape(info);
-
+#else
+  if (!SSL_get_server_tmp_key(ssl.get(), &raw_key)) return scope.Escape(info);
+#endif
   Local<Context> context = env->context();
   crypto::EVPKeyPointer key(raw_key);
 
