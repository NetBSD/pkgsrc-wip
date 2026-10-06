$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/wrappable.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/wrappable.cc
@@ -13,6 +13,9 @@ namespace gin {
 WrappableBase::WrappableBase() = default;
 
 WrappableBase::~WrappableBase() {
+  if (!wrapper_.IsEmpty()) {
+    wrapper_.ClearWeak();
+  }
   wrapper_.Reset();
 }
 
@@ -28,15 +31,24 @@ const char* WrappableBase::GetTypeName()
 void WrappableBase::FirstWeakCallback(
     const v8::WeakCallbackInfo<WrappableBase>& data) {
   WrappableBase* wrappable = data.GetParameter();
-  wrappable->dead_ = true;
-  wrappable->wrapper_.Reset();
-  data.SetSecondPassCallback(SecondWeakCallback);
+  WrappableBase* wrappable_from_field =
+      static_cast<WrappableBase*>(data.GetInternalField(1));
+  if (wrappable && wrappable == wrappable_from_field) {
+    wrappable->dead_ = true;
+    wrappable->wrapper_.Reset();
+    data.SetSecondPassCallback(SecondWeakCallback);
+  }
 }
 
 void WrappableBase::SecondWeakCallback(
     const v8::WeakCallbackInfo<WrappableBase>& data) {
+  if (IsolateHolder::DestroyedMicrotasksRunner()) {
+    return;
+  }
   WrappableBase* wrappable = data.GetParameter();
-  delete wrappable;
+  if (wrappable) {
+    delete wrappable;
+  }
 }
 
 v8::MaybeLocal<v8::Object> WrappableBase::GetWrapperImpl(v8::Isolate* isolate,
@@ -71,10 +83,16 @@ v8::MaybeLocal<v8::Object> WrappableBase
   void* values[] = {info, this};
   wrapper->SetAlignedPointerInInternalFields(2, indices, values);
   wrapper_.Reset(isolate, wrapper);
-  wrapper_.SetWeak(this, FirstWeakCallback, v8::WeakCallbackType::kParameter);
+  wrapper_.SetWeak(this, FirstWeakCallback, v8::WeakCallbackType::kInternalFields);
   return v8::MaybeLocal<v8::Object>(wrapper);
 }
 
+void WrappableBase::ClearWeak() {
+  if (!wrapper_.IsEmpty()) {
+    wrapper_.ClearWeak();
+  }
+}
+
 namespace internal {
 
 void* FromV8Impl(v8::Isolate* isolate, v8::Local<v8::Value> val,
