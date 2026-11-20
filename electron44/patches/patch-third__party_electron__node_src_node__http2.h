$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/src/node_http2.h.orig	2026-11-20 11:41:22.889579345 +0000
+++ third_party/electron_node/src/node_http2.h
@@ -146,6 +146,96 @@ struct Http2RcBufferPointerTraits {
 using Http2Headers = NgHeaders<Http2HeadersTraits>;
 using Http2RcBufferPointer = NgRcBufPointer<Http2RcBufferPointerTraits>;
 
+}  // namespace http2
+
+// ThinLTO: class template instantiations always have weak (linkonce_odr)
+// vtables. On Mach-O, LTO localizes weak unnamed_addr vtables during code
+// generation even when other LTO partitions still reference them, which
+// fails the link with undefined vtable symbols. This explicit specialization
+// is an ordinary class that can have a key function (the out-of-line
+// destructor), so its vtable is a strong symbol that ThinLTO must keep
+// external. The body is otherwise identical to the primary template in
+// node_http_common.h.
+template <>
+class NgRcBufPointer<http2::Http2RcBufferPointerTraits>::External
+    : public v8::String::ExternalOneByteStringResource {
+ public:
+  explicit External(
+      const NgRcBufPointer<http2::Http2RcBufferPointerTraits>& ptr)
+      : ptr_(ptr) {}
+
+  // Key function; defined in node_http2.cc to anchor the vtable.
+  ~External() override;
+
+  const char* data() const override {
+    return const_cast<const char*>(reinterpret_cast<char*>(ptr_.data()));
+  }
+
+  size_t length() const override {
+    return ptr_.len();
+  }
+
+  static inline
+  v8::MaybeLocal<v8::String> GetInternalizedString(
+      Environment* env,
+      const NgRcBufPointer<http2::Http2RcBufferPointerTraits>& ptr) {
+    return v8::String::NewFromOneByte(
+        env->isolate(),
+        ptr.data(),
+        v8::NewStringType::kInternalized,
+        ptr.len());
+  }
+
+  template <typename Allocator>
+  static v8::MaybeLocal<v8::String> New(
+      Allocator* allocator,
+      NgRcBufPointer<http2::Http2RcBufferPointerTraits> ptr) {
+    Environment* env = allocator->env();
+    if (ptr.IsStatic()) {
+      auto& static_str_map = env->isolate_data()->static_str_map;
+      const char* header_name = reinterpret_cast<const char*>(ptr.data());
+      v8::Eternal<v8::String>& eternal = static_str_map[header_name];
+      if (eternal.IsEmpty()) {
+        v8::Local<v8::String> str;
+        if (!GetInternalizedString(env, ptr).ToLocal(&str)) {
+          ptr.reset();
+          return {};
+        }
+        eternal.Set(env->isolate(), str);
+        return str;
+      }
+      return eternal.Get(env->isolate());
+    }
+
+    size_t len = ptr.len();
+
+    if (len == 0) {
+      ptr.reset();
+      return v8::String::Empty(env->isolate());
+    }
+
+    if (ptr.IsInternalizable() && len < 64) {
+      v8::MaybeLocal<v8::String> ret = GetInternalizedString(env, ptr);
+      ptr.reset();
+      return ret;
+    }
+
+    allocator->StopTrackingMemory(ptr.get());
+    External* h_str = new External(std::move(ptr));
+    v8::MaybeLocal<v8::String> str =
+        v8::String::NewExternalOneByte(env->isolate(), h_str);
+    if (str.IsEmpty())
+      delete h_str;
+
+    return str;
+  }
+
+ private:
+  NgRcBufPointer<http2::Http2RcBufferPointerTraits> ptr_;
+};
+
+namespace http2 {
+
 struct NgHttp2StreamWrite : public MemoryRetainer {
   BaseObjectPtr<AsyncWrap> req_wrap;
   uv_buf_t buf;
