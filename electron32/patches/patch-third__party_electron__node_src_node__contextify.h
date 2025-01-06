$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_contextify.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_contextify.h
@@ -99,7 +99,6 @@ class ContextifyContext : public BaseObj
       v8::Local<v8::Symbol> id_symbol,
       const errors::TryCatchScope& try_catch);
   static v8::ScriptCompiler::Source GetCommonJSSourceInstance(
-      v8::Isolate* isolate,
       v8::Local<v8::String> code,
       v8::Local<v8::String> filename,
       int line_offset,
@@ -112,42 +111,39 @@ class ContextifyContext : public BaseObj
       const v8::FunctionCallbackInfo<v8::Value>& args);
   static void WeakCallback(
       const v8::WeakCallbackInfo<ContextifyContext>& data);
-  static void PropertyGetterCallback(
+  static v8::Intercepted PropertyGetterCallback(
       v8::Local<v8::Name> property,
       const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void PropertySetterCallback(
+  static v8::Intercepted PropertySetterCallback(
       v8::Local<v8::Name> property,
       v8::Local<v8::Value> value,
-      const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void PropertyDescriptorCallback(
+      const v8::PropertyCallbackInfo<void>& args);
+  static v8::Intercepted PropertyDescriptorCallback(
       v8::Local<v8::Name> property,
       const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void PropertyDefinerCallback(
+  static v8::Intercepted PropertyDefinerCallback(
       v8::Local<v8::Name> property,
       const v8::PropertyDescriptor& desc,
-      const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void PropertyDeleterCallback(
+      const v8::PropertyCallbackInfo<void>& args);
+  static v8::Intercepted PropertyDeleterCallback(
       v8::Local<v8::Name> property,
       const v8::PropertyCallbackInfo<v8::Boolean>& args);
   static void PropertyEnumeratorCallback(
       const v8::PropertyCallbackInfo<v8::Array>& args);
-  static void IndexedPropertyGetterCallback(
-      uint32_t index,
-      const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void IndexedPropertySetterCallback(
+  static v8::Intercepted IndexedPropertyGetterCallback(
+      uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& args);
+  static v8::Intercepted IndexedPropertySetterCallback(
       uint32_t index,
       v8::Local<v8::Value> value,
-      const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void IndexedPropertyDescriptorCallback(
-      uint32_t index,
-      const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void IndexedPropertyDefinerCallback(
+      const v8::PropertyCallbackInfo<void>& args);
+  static v8::Intercepted IndexedPropertyDescriptorCallback(
+      uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& args);
+  static v8::Intercepted IndexedPropertyDefinerCallback(
       uint32_t index,
       const v8::PropertyDescriptor& desc,
-      const v8::PropertyCallbackInfo<v8::Value>& args);
-  static void IndexedPropertyDeleterCallback(
-      uint32_t index,
-      const v8::PropertyCallbackInfo<v8::Boolean>& args);
+      const v8::PropertyCallbackInfo<void>& args);
+  static v8::Intercepted IndexedPropertyDeleterCallback(
+      uint32_t index, const v8::PropertyCallbackInfo<v8::Boolean>& args);
 
   v8::Global<v8::Context> context_;
   std::unique_ptr<v8::MicrotaskQueue> microtask_queue_;
