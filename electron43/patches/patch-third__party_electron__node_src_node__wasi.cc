$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_wasi.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_wasi.cc
@@ -248,17 +248,18 @@ R WASI::WasiFunction<FT, F, R, Args...>:
   WASI* wasi = reinterpret_cast<WASI*>(BaseObject::FromJSObject(receiver));
   if (UNLIKELY(wasi == nullptr)) return EinvalError<R>();
 
-  if (UNLIKELY(options.wasm_memory == nullptr || wasi->memory_.IsEmpty())) {
-    // fallback to slow path which to throw an error about missing memory.
-    options.fallback = true;
+  v8::Isolate* isolate = receiver->GetIsolate();
+  v8::HandleScope handle_scope(isolate);
+  if (wasi->memory_.IsEmpty()) {
+    THROW_ERR_WASI_NOT_STARTED(isolate);
     return EinvalError<R>();
   }
-  uint8_t* memory = nullptr;
-  CHECK(LIKELY(options.wasm_memory->getStorageIfAligned(&memory)));
+  Local<ArrayBuffer> ab = wasi->memory_.Get(isolate)->Buffer();
+  size_t mem_size = ab->ByteLength();
+  char* mem_data = static_cast<char*>(ab->Data());
+  CHECK_NOT_NULL(mem_data);
 
-  return F(*wasi,
-           {reinterpret_cast<char*>(memory), options.wasm_memory->length()},
-           args...);
+  return F(*wasi, {mem_data, mem_size}, args...);
 }
 
 namespace {
