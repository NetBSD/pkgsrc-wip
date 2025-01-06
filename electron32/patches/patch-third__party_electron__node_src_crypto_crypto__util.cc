$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_util.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_util.cc
@@ -348,10 +348,35 @@ ByteSource& ByteSource::operator=(ByteSo
   return *this;
 }
 
-std::unique_ptr<BackingStore> ByteSource::ReleaseToBackingStore() {
+std::unique_ptr<BackingStore> ByteSource::ReleaseToBackingStore(Environment* env) {
   // It's ok for allocated_data_ to be nullptr but
   // only if size_ is zero.
   CHECK_IMPLIES(size_ > 0, allocated_data_ != nullptr);
+#if defined(V8_ENABLE_SANDBOX)
+  // When V8 sandboxed pointers are enabled, we have to copy into the memory
+  // cage. We still want to ensure we erase the data on free though, so
+  // provide a custom deleter that calls OPENSSL_cleanse.
+  if (!size())
+    return ArrayBuffer::NewBackingStore(env->isolate(), 0);
+  std::unique_ptr<ArrayBuffer::Allocator> allocator(ArrayBuffer::Allocator::NewDefaultAllocator());
+  void* v8_data = allocator->Allocate(size());
+  CHECK(v8_data);
+  memcpy(v8_data, allocated_data_, size());
+  OPENSSL_clear_free(allocated_data_, size());
+  std::unique_ptr<BackingStore> ptr = ArrayBuffer::NewBackingStore(
+      v8_data,
+      size(),
+      [](void* data, size_t length, void*) {
+        OPENSSL_cleanse(data, length);
+        std::unique_ptr<ArrayBuffer::Allocator> allocator(ArrayBuffer::Allocator::NewDefaultAllocator());
+        allocator->Free(data, length);
+      }, nullptr);
+  CHECK(ptr);
+  allocated_data_ = nullptr;
+  data_ = nullptr;
+  size_ = 0;
+  return ptr;
+#else
   std::unique_ptr<BackingStore> ptr = ArrayBuffer::NewBackingStore(
       allocated_data_,
       size(),
@@ -363,10 +388,11 @@ std::unique_ptr<BackingStore> ByteSource
   data_ = nullptr;
   size_ = 0;
   return ptr;
+#endif  // defined(V8_ENABLE_SANDBOX)
 }
 
 Local<ArrayBuffer> ByteSource::ToArrayBuffer(Environment* env) {
-  std::unique_ptr<BackingStore> store = ReleaseToBackingStore();
+  std::unique_ptr<BackingStore> store = ReleaseToBackingStore(env);
   return ArrayBuffer::New(env->isolate(), std::move(store));
 }
 
@@ -518,24 +544,15 @@ Maybe<void> Decorate(Environment* env,
     V(BIO)                                                                    \
     V(PKCS7)                                                                  \
     V(X509V3)                                                                 \
-    V(PKCS12)                                                                 \
     V(RAND)                                                                   \
-    V(DSO)                                                                    \
     V(ENGINE)                                                                 \
     V(OCSP)                                                                   \
     V(UI)                                                                     \
     V(COMP)                                                                   \
     V(ECDSA)                                                                  \
     V(ECDH)                                                                   \
-    V(OSSL_STORE)                                                             \
-    V(FIPS)                                                                   \
-    V(CMS)                                                                    \
-    V(TS)                                                                     \
     V(HMAC)                                                                   \
-    V(CT)                                                                     \
-    V(ASYNC)                                                                  \
-    V(KDF)                                                                    \
-    V(SM2)                                                                    \
+    V(HKDF)                                                                    \
     V(USER)                                                                   \
 
 #define V(name) case ERR_LIB_##name: lib = #name "_"; break;
@@ -712,11 +729,21 @@ namespace {
 // in which case this has the same semantics as
 // using OPENSSL_malloc. However, if the secure heap is
 // initialized, SecureBuffer will automatically use it.
+#if defined(V8_ENABLE_SANDBOX)
+// When V8 sandboxed pointers are enabled, the secure heap cannot be used as
+// all ArrayBuffers must be allocated inside the V8 memory cage.
+void SecureBuffer(const FunctionCallbackInfo<Value>& args) {
+  CHECK(args[0]->IsUint32());
+  uint32_t len = args[0].As<Uint32>()->Value();
+  Local<ArrayBuffer> buffer = ArrayBuffer::New(args.GetIsolate(), len);
+  args.GetReturnValue().Set(Uint8Array::New(buffer, 0, len));
+}
+#else
 void SecureBuffer(const FunctionCallbackInfo<Value>& args) {
   CHECK(args[0]->IsUint32());
   Environment* env = Environment::GetCurrent(args);
   uint32_t len = args[0].As<Uint32>()->Value();
-  void* data = OPENSSL_secure_zalloc(len);
+  void* data = OPENSSL_malloc(len);
   if (data == nullptr) {
     // There's no memory available for the allocation.
     // Return nothing.
@@ -727,18 +754,21 @@ void SecureBuffer(const FunctionCallback
           data,
           len,
           [](void* data, size_t len, void* deleter_data) {
-            OPENSSL_secure_clear_free(data, len);
+            OPENSSL_clear_free(data, len);
           },
           data);
   Local<ArrayBuffer> buffer = ArrayBuffer::New(env->isolate(), store);
   args.GetReturnValue().Set(Uint8Array::New(buffer, 0, len));
 }
+#endif  // defined(V8_ENABLE_SANDBOX)
 
 void SecureHeapUsed(const FunctionCallbackInfo<Value>& args) {
+#ifndef OPENSSL_IS_BORINGSSL
   Environment* env = Environment::GetCurrent(args);
   if (CRYPTO_secure_malloc_initialized())
     args.GetReturnValue().Set(
         BigInt::New(env->isolate(), CRYPTO_secure_used()));
+#endif
 }
 }  // namespace
 
