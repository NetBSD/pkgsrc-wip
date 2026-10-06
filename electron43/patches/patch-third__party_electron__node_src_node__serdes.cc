$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_serdes.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_serdes.cc
@@ -29,6 +29,11 @@ using v8::ValueSerializer;
 
 namespace serdes {
 
+v8::ArrayBuffer::Allocator* GetAllocator() {
+  static v8::ArrayBuffer::Allocator* allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
+  return allocator;
+}
+
 class SerializerContext : public BaseObject,
                           public ValueSerializer::Delegate {
  public:
@@ -37,10 +42,15 @@ class SerializerContext : public BaseObj
 
   ~SerializerContext() override = default;
 
+  // v8::ValueSerializer::Delegate
   void ThrowDataCloneError(Local<String> message) override;
   Maybe<bool> WriteHostObject(Isolate* isolate, Local<Object> object) override;
   Maybe<uint32_t> GetSharedArrayBufferId(
       Isolate* isolate, Local<SharedArrayBuffer> shared_array_buffer) override;
+  void* ReallocateBufferMemory(void* old_buffer,
+                               size_t old_length,
+                               size_t* new_length) override;
+  void FreeBufferMemory(void* buffer) override;
 
   static void SetTreatArrayBufferViewsAsHostObjects(
       const FunctionCallbackInfo<Value>& args);
@@ -61,6 +71,7 @@ class SerializerContext : public BaseObj
 
  private:
   ValueSerializer serializer_;
+  size_t last_length_ = 0;
 };
 
 class DeserializerContext : public BaseObject,
@@ -144,6 +155,24 @@ Maybe<uint32_t> SerializerContext::GetSh
   return id.ToLocalChecked()->Uint32Value(env()->context());
 }
 
+void* SerializerContext::ReallocateBufferMemory(void* old_buffer,
+                                                size_t requested_size,
+                                                size_t* new_length) {
+  *new_length = std::max(static_cast<size_t>(4096), requested_size);
+  if (old_buffer) {
+    void* ret = GetAllocator()->Reallocate(old_buffer, last_length_, *new_length);
+    last_length_ = *new_length;
+    return ret;
+  } else {
+    last_length_ = *new_length;
+    return GetAllocator()->Allocate(*new_length);
+  }
+}
+
+void SerializerContext::FreeBufferMemory(void* buffer) {
+  GetAllocator()->Free(buffer, last_length_);
+}
+
 Maybe<bool> SerializerContext::WriteHostObject(Isolate* isolate,
                                                Local<Object> input) {
   MaybeLocal<Value> ret;
@@ -209,9 +238,14 @@ void SerializerContext::ReleaseBuffer(co
   // Note: Both ValueSerializer and this Buffer::New() variant use malloc()
   // as the underlying allocator.
   std::pair<uint8_t*, size_t> ret = ctx->serializer_.Release();
-  auto buf = Buffer::New(ctx->env(),
-                         reinterpret_cast<char*>(ret.first),
-                         ret.second);
+  std::unique_ptr<v8::BackingStore> bs =
+      v8::ArrayBuffer::NewBackingStore(reinterpret_cast<char*>(ret.first), ret.second,
+        [](void* data, size_t length, void* deleter_data) {
+          if (data) GetAllocator()->Free(reinterpret_cast<char*>(data), length);
+        }, nullptr);
+  Local<ArrayBuffer> ab = v8::ArrayBuffer::New(ctx->env()->isolate(), std::move(bs));
+
+  auto buf = Buffer::New(ctx->env(), ab, 0, ret.second);
 
   if (!buf.IsEmpty()) {
     args.GetReturnValue().Set(buf.ToLocalChecked());
