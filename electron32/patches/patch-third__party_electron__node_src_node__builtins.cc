$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_builtins.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_builtins.cc
@@ -11,7 +11,6 @@ namespace node {
 namespace builtins {
 
 using v8::Context;
-using v8::DEFAULT;
 using v8::EscapableHandleScope;
 using v8::Function;
 using v8::FunctionCallbackInfo;
@@ -35,6 +34,7 @@ using v8::Value;
 BuiltinLoader::BuiltinLoader()
     : config_(GetConfig()), code_cache_(std::make_shared<BuiltinCodeCache>()) {
   LoadJavaScriptSource();
+  LoadEmbedderJavaScriptSource();
 #ifdef NODE_SHARED_BUILTIN_CJS_MODULE_LEXER_LEXER_PATH
   AddExternalizedBuiltin(
       "internal/deps/cjs-module-lexer/lexer",
@@ -266,7 +266,7 @@ MaybeLocal<Function> BuiltinLoader::Look
   std::string filename_s = std::string("node:") + id;
   Local<String> filename =
       OneByteString(isolate, filename_s.c_str(), filename_s.size());
-  ScriptOrigin origin(isolate, filename, 0, 0, true);
+  ScriptOrigin origin(filename, 0, 0, true);
 
   BuiltinCodeCacheData cached_data{};
   {
@@ -719,7 +719,6 @@ void BuiltinLoader::CreatePerIsolateProp
                                 nullptr,
                                 Local<Value>(),
                                 None,
-                                DEFAULT,
                                 SideEffectType::kHasNoSideEffect);
 
   target->SetNativeDataProperty(FIXED_ONE_BYTE_STRING(isolate, "builtinIds"),
@@ -727,7 +726,6 @@ void BuiltinLoader::CreatePerIsolateProp
                                 nullptr,
                                 Local<Value>(),
                                 None,
-                                DEFAULT,
                                 SideEffectType::kHasNoSideEffect);
 
   target->SetNativeDataProperty(
@@ -736,7 +734,6 @@ void BuiltinLoader::CreatePerIsolateProp
       nullptr,
       Local<Value>(),
       None,
-      DEFAULT,
       SideEffectType::kHasNoSideEffect);
 
   target->SetNativeDataProperty(FIXED_ONE_BYTE_STRING(isolate, "natives"),
@@ -744,7 +741,6 @@ void BuiltinLoader::CreatePerIsolateProp
                                 nullptr,
                                 Local<Value>(),
                                 None,
-                                DEFAULT,
                                 SideEffectType::kHasNoSideEffect);
 
   SetMethod(isolate, target, "getCacheUsage", BuiltinLoader::GetCacheUsage);
@@ -773,6 +769,7 @@ void BuiltinLoader::RegisterExternalRefe
   registry->Register(GetNatives);
 
   RegisterExternalReferencesForInternalizedBuiltinCode(registry);
+  EmbedderRegisterExternalReferencesForInternalizedBuiltinCode(registry);
 }
 
 }  // namespace builtins
