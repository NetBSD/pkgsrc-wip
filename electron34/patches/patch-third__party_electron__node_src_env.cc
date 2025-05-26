$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/env.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/env.cc
@@ -22,6 +22,7 @@
 #include "util-inl.h"
 #include "v8-cppgc.h"
 #include "v8-profiler.h"
+#include "v8-sandbox.h"  // v8::Object::Wrap(), v8::Object::Unwrap()
 
 #include <algorithm>
 #include <atomic>
@@ -68,7 +69,6 @@ using v8::TryCatch;
 using v8::Uint32;
 using v8::Undefined;
 using v8::Value;
-using v8::WrapperDescriptor;
 using worker::Worker;
 
 int const ContextEmbedderTag::kNodeContextTag = 0x6e6f64;
@@ -530,6 +530,14 @@ void IsolateData::CreateProperties() {
   CreateEnvProxyTemplate(this);
 }
 
+// Previously, the general convention of the wrappable layout for cppgc in
+// the ecosystem is:
+// [  0  ] -> embedder id
+// [  1  ] -> wrappable instance
+// Now V8 has deprecated this layout-based tracing enablement, embedders
+// should simply use v8::Object::Wrap() and v8::Object::Unwrap(). We preserve
+// this layout only to distinguish internally how the memory of a Node.js
+// wrapper is managed or whether a wrapper is managed by Node.js.
 constexpr uint16_t kDefaultCppGCEmbedderID = 0x90de;
 Mutex IsolateData::isolate_data_mutex_;
 std::unordered_map<uint16_t, std::unique_ptr<PerIsolateWrapperData>>
@@ -567,36 +575,16 @@ IsolateData::IsolateData(Isolate* isolat
   v8::CppHeap* cpp_heap = isolate->GetCppHeap();
 
   uint16_t cppgc_id = kDefaultCppGCEmbedderID;
-  if (cpp_heap != nullptr) {
-    // The general convention of the wrappable layout for cppgc in the
-    // ecosystem is:
-    // [  0  ] -> embedder id
-    // [  1  ] -> wrappable instance
-    // If the Isolate includes a CppHeap attached by another embedder,
-    // And if they also use the field 0 for the ID, we DCHECK that
-    // the layout matches our layout, and record the embedder ID for cppgc
-    // to avoid accidentally enabling cppgc on non-cppgc-managed wrappers .
-    v8::WrapperDescriptor descriptor = cpp_heap->wrapper_descriptor();
-    if (descriptor.wrappable_type_index == BaseObject::kEmbedderType) {
-      cppgc_id = descriptor.embedder_id_for_garbage_collected;
-      DCHECK_EQ(descriptor.wrappable_instance_index, BaseObject::kSlot);
-    }
-    // If the CppHeap uses the slot we use to put non-cppgc-traced BaseObject
-    // for embedder ID, V8 could accidentally enable cppgc on them. So
-    // safe guard against this.
-    DCHECK_NE(descriptor.wrappable_type_index, BaseObject::kSlot);
-  } else {
-    cpp_heap_ = CppHeap::Create(
-        platform,
-        CppHeapCreateParams{
-            {},
-            WrapperDescriptor(
-                BaseObject::kEmbedderType, BaseObject::kSlot, cppgc_id)});
-    isolate->AttachCppHeap(cpp_heap_.get());
-  }
   // We do not care about overflow since we just want this to be different
   // from the cppgc id.
   uint16_t non_cppgc_id = cppgc_id + 1;
+  if (cpp_heap == nullptr) {
+    cpp_heap_ = CppHeap::Create(platform, v8::CppHeapCreateParams{{}});
+    // TODO(joyeecheung): pass it into v8::Isolate::CreateParams and let V8
+    // own it when we can keep the isolate registered/task runner discoverable
+    // during isolate disposal.
+    isolate->AttachCppHeap(cpp_heap_.get());
+  }
 
   {
     // GC could still be run after the IsolateData is destroyed, so we store
@@ -628,11 +616,12 @@ IsolateData::~IsolateData() {
   }
 }
 
-// Public API
+// Deprecated API, embedders should use v8::Object::Wrap() directly instead.
 void SetCppgcReference(Isolate* isolate,
                        Local<Object> object,
                        void* wrappable) {
-  IsolateData::SetCppgcReference(isolate, object, wrappable);
+  v8::Object::Wrap<v8::CppHeapPointerTag::kDefaultTag>(
+      isolate, object, wrappable);
 }
 
 void IsolateData::MemoryInfo(MemoryTracker* tracker) const {
