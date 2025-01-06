$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/base_object-inl.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/base_object-inl.h
@@ -132,19 +132,18 @@ v8::EmbedderGraph::Node::Detachedness Ba
 
 template <int Field>
 void BaseObject::InternalFieldGet(
-    v8::Local<v8::String> property,
-    const v8::PropertyCallbackInfo<v8::Value>& info) {
-  info.GetReturnValue().Set(
-      info.This()->GetInternalField(Field).As<v8::Value>());
+    const v8::FunctionCallbackInfo<v8::Value>& args) {
+  args.GetReturnValue().Set(
+      args.This()->GetInternalField(Field).As<v8::Value>());
 }
 
-template <int Field, bool (v8::Value::* typecheck)() const>
-void BaseObject::InternalFieldSet(v8::Local<v8::String> property,
-                                  v8::Local<v8::Value> value,
-                                  const v8::PropertyCallbackInfo<void>& info) {
+template <int Field, bool (v8::Value::*typecheck)() const>
+void BaseObject::InternalFieldSet(
+    const v8::FunctionCallbackInfo<v8::Value>& args) {
+  v8::Local<v8::Value> value = args[0];
   // This could be e.g. value->IsFunction().
   CHECK(((*value)->*typecheck)());
-  info.This()->SetInternalField(Field, value);
+  args.This()->SetInternalField(Field, value);
 }
 
 bool BaseObject::has_pointer_data() const {
