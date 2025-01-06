$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_trace_events.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_trace_events.cc
@@ -132,12 +132,28 @@ static void GetCategoryEnabledBuffer(con
   const uint8_t* enabled_pointer =
       TRACE_EVENT_API_GET_CATEGORY_GROUP_ENABLED(category_name.out());
   uint8_t* enabled_pointer_cast = const_cast<uint8_t*>(enabled_pointer);
+  uint8_t size = sizeof(*enabled_pointer_cast);
 
+#if defined(V8_ENABLE_SANDBOX)
+  std::unique_ptr<ArrayBuffer::Allocator> allocator(ArrayBuffer::Allocator::NewDefaultAllocator());
+  void* v8_data = allocator->Allocate(size);
+  CHECK(v8_data);
+  memcpy(v8_data, enabled_pointer_cast, size);
+  std::unique_ptr<BackingStore> bs = ArrayBuffer::NewBackingStore(
+      v8_data,
+      size,
+      [](void* data, size_t length, void*) {
+        std::unique_ptr<ArrayBuffer::Allocator> allocator(ArrayBuffer::Allocator::NewDefaultAllocator());
+        allocator->Free(data, length);
+      }, nullptr);
+#else
   std::unique_ptr<BackingStore> bs = ArrayBuffer::NewBackingStore(
       enabled_pointer_cast,
-      sizeof(*enabled_pointer_cast),
+      size,
       [](void*, size_t, void*) {},
       nullptr);
+#endif
+
   auto ab = ArrayBuffer::New(isolate, std::move(bs));
   v8::Local<Uint8Array> u8 = v8::Uint8Array::New(ab, 0, 1);
 
