$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/cctest/test_cppgc.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/cctest/test_cppgc.cc
@@ -3,16 +3,12 @@
 #include <cppgc/heap.h>
 #include <node.h>
 #include <v8-cppgc.h>
+#include <v8-sandbox.h>
 #include <v8.h>
 #include "node_test_fixture.h"
 
 // This tests that Node.js can work with an existing CppHeap.
 
-// Mimic the Blink layout.
-static int kWrappableTypeIndex = 0;
-static int kWrappableInstanceIndex = 1;
-static uint16_t kEmbedderID = 0x1;
-
 // Mimic a class that does not know about Node.js.
 class CppGCed : public cppgc::GarbageCollected<CppGCed> {
  public:
@@ -23,12 +19,11 @@ class CppGCed : public cppgc::GarbageCol
   static void New(const v8::FunctionCallbackInfo<v8::Value>& args) {
     v8::Isolate* isolate = args.GetIsolate();
     v8::Local<v8::Object> js_object = args.This();
-    CppGCed* gc_object = cppgc::MakeGarbageCollected<CppGCed>(
-        isolate->GetCppHeap()->GetAllocationHandle());
-    js_object->SetAlignedPointerInInternalField(kWrappableTypeIndex,
-                                                &kEmbedderID);
-    js_object->SetAlignedPointerInInternalField(kWrappableInstanceIndex,
-                                                gc_object);
+    auto* heap = isolate->GetCppHeap();
+    CHECK_NOT_NULL(heap);
+    CppGCed* gc_object =
+        cppgc::MakeGarbageCollected<CppGCed>(heap->GetAllocationHandle());
+    node::SetCppgcReference(isolate, js_object, gc_object);
     kConstructCount++;
     args.GetReturnValue().Set(js_object);
   }
@@ -36,8 +31,6 @@ class CppGCed : public cppgc::GarbageCol
   static v8::Local<v8::Function> GetConstructor(
       v8::Local<v8::Context> context) {
     auto ft = v8::FunctionTemplate::New(context->GetIsolate(), New);
-    auto ot = ft->InstanceTemplate();
-    ot->SetInternalFieldCount(2);
     return ft->GetFunction(context).ToLocalChecked();
   }
 
@@ -58,12 +51,12 @@ TEST_F(NodeZeroIsolateTestFixture, Exist
 
   // Create and attach the CppHeap before we set up the IsolateData so that
   // it recognizes the existing heap.
-  std::unique_ptr<v8::CppHeap> cpp_heap = v8::CppHeap::Create(
-      platform.get(),
-      v8::CppHeapCreateParams(
-          {},
-          v8::WrapperDescriptor(
-              kWrappableTypeIndex, kWrappableInstanceIndex, kEmbedderID)));
+  std::unique_ptr<v8::CppHeap> cpp_heap =
+      v8::CppHeap::Create(platform.get(), v8::CppHeapCreateParams{{}});
+
+  // TODO(joyeecheung): pass it into v8::Isolate::CreateParams and let V8
+  // own it when we can keep the isolate registered/task runner discoverable
+  // during isolate disposal.
   isolate->AttachCppHeap(cpp_heap.get());
 
   // Try creating Context + IsolateData + Environment.
