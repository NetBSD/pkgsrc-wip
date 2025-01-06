$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/bindings/core/v8/v8_initializer.cc.orig	2024-10-18 12:34:34.740490000 +0000
+++ third_party/blink/renderer/bindings/core/v8/v8_initializer.cc
@@ -623,7 +623,9 @@ bool WasmJSPromiseIntegrationEnabledCall
       execution_context);
 }
 
-v8::MaybeLocal<v8::Promise> HostImportModuleDynamically(
+}
+
+v8::MaybeLocal<v8::Promise> V8Initializer::HostImportModuleDynamically(
     v8::Local<v8::Context> context,
     v8::Local<v8::Data> v8_host_defined_options,
     v8::Local<v8::Value> v8_referrer_resource_url,
@@ -701,7 +703,7 @@ v8::MaybeLocal<v8::Promise> HostImportMo
 }
 
 // https://html.spec.whatwg.org/C/#hostgetimportmetaproperties
-void HostGetImportMetaProperties(v8::Local<v8::Context> context,
+void V8Initializer::HostGetImportMetaProperties(v8::Local<v8::Context> context,
                                  v8::Local<v8::Module> module,
                                  v8::Local<v8::Object> meta) {
   v8::Isolate* isolate = context->GetIsolate();
@@ -744,9 +746,6 @@ std::ostream& operator<<(std::ostream& o
   return os;
 }
 
-}  // namespace
-
-// static
 void V8Initializer::InitializeV8Common(v8::Isolate* isolate) {
   // Set up garbage collection before setting up anything else as V8 may trigger
   // GCs during Blink setup.
@@ -766,9 +765,9 @@ void V8Initializer::InitializeV8Common(v
   isolate->SetWasmJSPIEnabledCallback(WasmJSPromiseIntegrationEnabledCallback);
   isolate->SetSharedArrayBufferConstructorEnabledCallback(
       SharedArrayBufferConstructorEnabledCallback);
-  isolate->SetHostImportModuleDynamicallyCallback(HostImportModuleDynamically);
+  isolate->SetHostImportModuleDynamicallyCallback(V8Initializer::HostImportModuleDynamically);
   isolate->SetHostInitializeImportMetaObjectCallback(
-      HostGetImportMetaProperties);
+      V8Initializer::HostGetImportMetaProperties);
   isolate->SetMetricsRecorder(std::make_shared<V8MetricsRecorder>(isolate));
 
 #if BUILDFLAG(IS_WIN)
