$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_util.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_util.h
@@ -285,7 +285,7 @@ class ByteSource {
   // Creates a v8::BackingStore that takes over responsibility for
   // any allocated data. The ByteSource will be reset with size = 0
   // after being called.
-  std::unique_ptr<v8::BackingStore> ReleaseToBackingStore();
+  std::unique_ptr<v8::BackingStore> ReleaseToBackingStore(Environment* env);
 
   v8::Local<v8::ArrayBuffer> ToArrayBuffer(Environment* env);
 
