$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/addons/cppgc-object/binding.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/addons/cppgc-object/binding.cc
@@ -1,8 +1,10 @@
+#include <assert.h>
 #include <cppgc/allocation.h>
 #include <cppgc/garbage-collected.h>
 #include <cppgc/heap.h>
 #include <node.h>
 #include <v8-cppgc.h>
+#include <v8-sandbox.h>
 #include <v8.h>
 #include <algorithm>
 
@@ -15,8 +17,10 @@ class CppGCed : public cppgc::GarbageCol
   static void New(const v8::FunctionCallbackInfo<v8::Value>& args) {
     v8::Isolate* isolate = args.GetIsolate();
     v8::Local<v8::Object> js_object = args.This();
-    CppGCed* gc_object = cppgc::MakeGarbageCollected<CppGCed>(
-        isolate->GetCppHeap()->GetAllocationHandle());
+    auto* heap = isolate->GetCppHeap();
+    assert(heap != nullptr);
+    CppGCed* gc_object =
+        cppgc::MakeGarbageCollected<CppGCed>(heap->GetAllocationHandle());
     node::SetCppgcReference(isolate, js_object, gc_object);
     args.GetReturnValue().Set(js_object);
   }
@@ -24,12 +28,6 @@ class CppGCed : public cppgc::GarbageCol
   static v8::Local<v8::Function> GetConstructor(
       v8::Local<v8::Context> context) {
     auto ft = v8::FunctionTemplate::New(context->GetIsolate(), New);
-    auto ot = ft->InstanceTemplate();
-    v8::WrapperDescriptor descriptor =
-        context->GetIsolate()->GetCppHeap()->wrapper_descriptor();
-    uint16_t required_size = std::max(descriptor.wrappable_instance_index,
-                                      descriptor.wrappable_type_index);
-    ot->SetInternalFieldCount(required_size + 1);
     return ft->GetFunction(context).ToLocalChecked();
   }
 
