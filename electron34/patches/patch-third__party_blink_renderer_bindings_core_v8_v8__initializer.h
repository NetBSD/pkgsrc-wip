$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/bindings/core/v8/v8_initializer.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/bindings/core/v8/v8_initializer.h
@@ -85,6 +85,17 @@ class CORE_EXPORT V8Initializer {
   static void PromiseRejectHandlerInMainThread(v8::PromiseRejectMessage data);
   static void ExceptionPropagationCallback(v8::ExceptionPropagationMessage);
 
+  static v8::MaybeLocal<v8::Promise> HostImportModuleDynamically(
+    v8::Local<v8::Context> context,
+    v8::Local<v8::Data> v8_host_defined_options,
+    v8::Local<v8::Value> v8_referrer_resource_url,
+    v8::Local<v8::String> v8_specifier,
+    v8::Local<v8::FixedArray> v8_import_assertions);
+
+  static void HostGetImportMetaProperties(v8::Local<v8::Context> context,
+                                          v8::Local<v8::Module> module,
+                                          v8::Local<v8::Object> meta);
+
   static void WasmAsyncResolvePromiseCallback(
       v8::Isolate* isolate,
       v8::Local<v8::Context> context,
