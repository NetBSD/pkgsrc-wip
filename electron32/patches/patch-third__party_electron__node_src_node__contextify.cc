$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_contextify.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_contextify.cc
@@ -49,6 +49,7 @@ using v8::FunctionTemplate;
 using v8::HandleScope;
 using v8::IndexedPropertyHandlerConfiguration;
 using v8::Int32;
+using v8::Intercepted;
 using v8::Isolate;
 using v8::Just;
 using v8::Local;
@@ -484,16 +485,20 @@ bool ContextifyContext::IsStillInitializ
 }
 
 // static
-void ContextifyContext::PropertyGetterCallback(
-    Local<Name> property,
-    const PropertyCallbackInfo<Value>& args) {
+Intercepted ContextifyContext::PropertyGetterCallback(
+    Local<Name> property, const PropertyCallbackInfo<Value>& args) {
+  Environment* env = Environment::GetCurrent(args);
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
   Local<Context> context = ctx->context();
   Local<Object> sandbox = ctx->sandbox();
+
+  TryCatchScope try_catch(env);
   MaybeLocal<Value> maybe_rv =
       sandbox->GetRealNamedProperty(context, property);
   if (maybe_rv.IsEmpty()) {
@@ -503,22 +508,31 @@ void ContextifyContext::PropertyGetterCa
 
   Local<Value> rv;
   if (maybe_rv.ToLocal(&rv)) {
+    if (try_catch.HasCaught() &&
+        !try_catch.HasTerminated()) {
+      try_catch.ReThrow();
+    }
+
     if (rv == sandbox)
       rv = ctx->global_proxy();
 
     args.GetReturnValue().Set(rv);
+    return Intercepted::kYes;
   }
+  return Intercepted::kNo;
 }
 
 // static
-void ContextifyContext::PropertySetterCallback(
+Intercepted ContextifyContext::PropertySetterCallback(
     Local<Name> property,
     Local<Value> value,
-    const PropertyCallbackInfo<Value>& args) {
+    const PropertyCallbackInfo<void>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
   Local<Context> context = ctx->context();
   PropertyAttribute attributes = PropertyAttribute::None;
@@ -536,8 +550,9 @@ void ContextifyContext::PropertySetterCa
       (static_cast<int>(attributes) &
       static_cast<int>(PropertyAttribute::ReadOnly));
 
-  if (read_only)
-    return;
+  if (read_only) {
+    return Intercepted::kNo;
+  }
 
   // true for x = 5
   // false for this.x = 5
@@ -556,11 +571,16 @@ void ContextifyContext::PropertySetterCa
 
   bool is_declared = is_declared_on_global_proxy || is_declared_on_sandbox;
   if (!is_declared && args.ShouldThrowOnError() && is_contextual_store &&
-      !is_function)
-    return;
+      !is_function) {
+    return Intercepted::kNo;
+  }
 
-  if (!is_declared && property->IsSymbol()) return;
-  if (ctx->sandbox()->Set(context, property, value).IsNothing()) return;
+  if (!is_declared && property->IsSymbol()) {
+    return Intercepted::kNo;
+  }
+  if (ctx->sandbox()->Set(context, property, value).IsNothing()) {
+    return Intercepted::kNo;
+  }
 
   Local<Value> desc;
   if (is_declared_on_sandbox &&
@@ -574,19 +594,23 @@ void ContextifyContext::PropertySetterCa
     // We have to specify the return value for any contextual or get/set
     // property
     if (desc_obj->HasOwnProperty(context, env->get_string()).FromMaybe(false) ||
-        desc_obj->HasOwnProperty(context, env->set_string()).FromMaybe(false))
+        desc_obj->HasOwnProperty(context, env->set_string()).FromMaybe(false)) {
       args.GetReturnValue().Set(value);
+      return Intercepted::kYes;
+    }
   }
+  return Intercepted::kNo;
 }
 
 // static
-void ContextifyContext::PropertyDescriptorCallback(
-    Local<Name> property,
-    const PropertyCallbackInfo<Value>& args) {
+Intercepted ContextifyContext::PropertyDescriptorCallback(
+    Local<Name> property, const PropertyCallbackInfo<Value>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
   Local<Context> context = ctx->context();
 
@@ -596,19 +620,23 @@ void ContextifyContext::PropertyDescript
     Local<Value> desc;
     if (sandbox->GetOwnPropertyDescriptor(context, property).ToLocal(&desc)) {
       args.GetReturnValue().Set(desc);
+      return Intercepted::kYes;
     }
   }
+  return Intercepted::kNo;
 }
 
 // static
-void ContextifyContext::PropertyDefinerCallback(
+Intercepted ContextifyContext::PropertyDefinerCallback(
     Local<Name> property,
     const PropertyDescriptor& desc,
-    const PropertyCallbackInfo<Value>& args) {
+    const PropertyCallbackInfo<void>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
   Local<Context> context = ctx->context();
   Isolate* isolate = context->GetIsolate();
@@ -627,7 +655,7 @@ void ContextifyContext::PropertyDefinerC
   // If the property is set on the global as neither writable nor
   // configurable, don't change it on the global or sandbox.
   if (is_declared && read_only && dont_delete) {
-    return;
+    return Intercepted::kNo;
   }
 
   Local<Object> sandbox = ctx->sandbox();
@@ -650,6 +678,9 @@ void ContextifyContext::PropertyDefinerC
         desc.has_set() ? desc.set() : Undefined(isolate).As<Value>());
 
     define_prop_on_sandbox(&desc_for_sandbox);
+    // TODO(https://github.com/nodejs/node/issues/52634): this should return
+    // kYes to behave according to the expected semantics.
+    return Intercepted::kNo;
   } else {
     Local<Value> value =
         desc.has_value() ? desc.value() : Undefined(isolate).As<Value>();
@@ -661,26 +692,32 @@ void ContextifyContext::PropertyDefinerC
       PropertyDescriptor desc_for_sandbox(value);
       define_prop_on_sandbox(&desc_for_sandbox);
     }
+    // TODO(https://github.com/nodejs/node/issues/52634): this should return
+    // kYes to behave according to the expected semantics.
+    return Intercepted::kNo;
   }
 }
 
 // static
-void ContextifyContext::PropertyDeleterCallback(
-    Local<Name> property,
-    const PropertyCallbackInfo<Boolean>& args) {
+Intercepted ContextifyContext::PropertyDeleterCallback(
+    Local<Name> property, const PropertyCallbackInfo<Boolean>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
   Maybe<bool> success = ctx->sandbox()->Delete(ctx->context(), property);
 
-  if (success.FromMaybe(false))
-    return;
+  if (success.FromMaybe(false)) {
+    return Intercepted::kNo;
+  }
 
   // Delete failed on the sandbox, intercept and do not delete on
   // the global object.
   args.GetReturnValue().Set(false);
+  return Intercepted::kYes;
 }
 
 // static
@@ -700,76 +737,84 @@ void ContextifyContext::PropertyEnumerat
 }
 
 // static
-void ContextifyContext::IndexedPropertyGetterCallback(
-    uint32_t index,
-    const PropertyCallbackInfo<Value>& args) {
+Intercepted ContextifyContext::IndexedPropertyGetterCallback(
+    uint32_t index, const PropertyCallbackInfo<Value>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
-  ContextifyContext::PropertyGetterCallback(
+  return ContextifyContext::PropertyGetterCallback(
       Uint32ToName(ctx->context(), index), args);
 }
 
-
-void ContextifyContext::IndexedPropertySetterCallback(
+Intercepted ContextifyContext::IndexedPropertySetterCallback(
     uint32_t index,
     Local<Value> value,
-    const PropertyCallbackInfo<Value>& args) {
+    const PropertyCallbackInfo<void>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
-  ContextifyContext::PropertySetterCallback(
+  return ContextifyContext::PropertySetterCallback(
       Uint32ToName(ctx->context(), index), value, args);
 }
 
 // static
-void ContextifyContext::IndexedPropertyDescriptorCallback(
-    uint32_t index,
-    const PropertyCallbackInfo<Value>& args) {
+Intercepted ContextifyContext::IndexedPropertyDescriptorCallback(
+    uint32_t index, const PropertyCallbackInfo<Value>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
-  ContextifyContext::PropertyDescriptorCallback(
+  return ContextifyContext::PropertyDescriptorCallback(
       Uint32ToName(ctx->context(), index), args);
 }
 
 
-void ContextifyContext::IndexedPropertyDefinerCallback(
+Intercepted ContextifyContext::IndexedPropertyDefinerCallback(
     uint32_t index,
     const PropertyDescriptor& desc,
-    const PropertyCallbackInfo<Value>& args) {
+    const PropertyCallbackInfo<void>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
-  ContextifyContext::PropertyDefinerCallback(
+  return ContextifyContext::PropertyDefinerCallback(
       Uint32ToName(ctx->context(), index), desc, args);
 }
 
 // static
-void ContextifyContext::IndexedPropertyDeleterCallback(
-    uint32_t index,
-    const PropertyCallbackInfo<Boolean>& args) {
+Intercepted ContextifyContext::IndexedPropertyDeleterCallback(
+    uint32_t index, const PropertyCallbackInfo<Boolean>& args) {
   ContextifyContext* ctx = ContextifyContext::Get(args);
 
   // Still initializing
-  if (IsStillInitializing(ctx)) return;
+  if (IsStillInitializing(ctx)) {
+    return Intercepted::kNo;
+  }
 
   Maybe<bool> success = ctx->sandbox()->Delete(ctx->context(), index);
 
-  if (success.FromMaybe(false))
-    return;
+  if (success.FromMaybe(false)) {
+    return Intercepted::kNo;
+  }
 
   // Delete failed on the sandbox, intercept and do not delete on
   // the global object.
   args.GetReturnValue().Set(false);
+  return Intercepted::kYes;
 }
 
 void ContextifyScript::CreatePerIsolateProperties(
@@ -869,16 +914,15 @@ void ContextifyScript::New(const Functio
   host_defined_options->Set(
       isolate, loader::HostDefinedOptions::kID, id_symbol);
 
-  ScriptOrigin origin(isolate,
-                      filename,
-                      line_offset,                          // line offset
-                      column_offset,                        // column offset
-                      true,                                 // is cross origin
-                      -1,                                   // script id
-                      Local<Value>(),                       // source map URL
-                      false,                                // is opaque (?)
-                      false,                                // is WASM
-                      false,                                // is ES Module
+  ScriptOrigin origin(filename,
+                      line_offset,     // line offset
+                      column_offset,   // column offset
+                      true,            // is cross origin
+                      -1,              // script id
+                      Local<Value>(),  // source map URL
+                      false,           // is opaque (?)
+                      false,           // is WASM
+                      false,           // is ES Module
                       host_defined_options);
   ScriptCompiler::Source source(code, origin, cached_data);
   ScriptCompiler::CompileOptions compile_options =
@@ -990,7 +1034,7 @@ MaybeLocal<Function> CompileFunction(Loc
                                      Local<String> filename,
                                      Local<String> content,
                                      std::vector<Local<String>>* parameters) {
-  ScriptOrigin script_origin(context->GetIsolate(), filename, 0, 0, true);
+  ScriptOrigin script_origin(filename, 0, 0, true);
   ScriptCompiler::Source script_source(content, script_origin);
 
   return ScriptCompiler::CompileFunction(context,
@@ -1100,7 +1144,6 @@ bool ContextifyScript::EvalMachine(Local
   }
 
   TryCatchScope try_catch(env);
-  Isolate::SafeForTerminationScope safe_for_termination(env->isolate());
   ContextifyScript* wrapped_script;
   ASSIGN_OR_RETURN_UNWRAP(&wrapped_script, args.This(), false);
   Local<UnboundScript> unbound_script =
@@ -1278,8 +1321,7 @@ void ContextifyContext::CompileFunction(
   Local<PrimitiveArray> host_defined_options =
       GetHostDefinedOptions(isolate, id_symbol);
   ScriptCompiler::Source source =
-      GetCommonJSSourceInstance(isolate,
-                                code,
+      GetCommonJSSourceInstance(code,
                                 filename,
                                 line_offset,
                                 column_offset,
@@ -1334,15 +1376,13 @@ void ContextifyContext::CompileFunction(
 }
 
 ScriptCompiler::Source ContextifyContext::GetCommonJSSourceInstance(
-    Isolate* isolate,
     Local<String> code,
     Local<String> filename,
     int line_offset,
     int column_offset,
     Local<PrimitiveArray> host_defined_options,
     ScriptCompiler::CachedData* cached_data) {
-  ScriptOrigin origin(isolate,
-                      filename,
+  ScriptOrigin origin(filename,
                       line_offset,     // line offset
                       column_offset,   // column offset
                       true,            // is cross origin
@@ -1520,7 +1560,7 @@ void ContextifyContext::ContainsModuleSy
   Local<PrimitiveArray> host_defined_options =
       GetHostDefinedOptions(isolate, id_symbol);
   ScriptCompiler::Source source = GetCommonJSSourceInstance(
-      isolate, code, filename, 0, 0, host_defined_options, nullptr);
+      code, filename, 0, 0, host_defined_options, nullptr);
   ScriptCompiler::CompileOptions options = GetCompileOptions(source);
 
   std::vector<Local<String>> params = GetCJSParameters(env->isolate_data());
@@ -1568,7 +1608,7 @@ void ContextifyContext::ContainsModuleSy
               code,
               String::NewFromUtf8(isolate, "})();").ToLocalChecked());
           ScriptCompiler::Source wrapped_source = GetCommonJSSourceInstance(
-              isolate, code, filename, 0, 0, host_defined_options, nullptr);
+              code, filename, 0, 0, host_defined_options, nullptr);
           std::ignore = ScriptCompiler::CompileFunction(
               context,
               &wrapped_source,
@@ -1621,8 +1661,7 @@ static void CompileFunctionForCJSLoader(
 
   Local<Symbol> symbol = env->vm_dynamic_import_default_internal();
   Local<PrimitiveArray> hdo = GetHostDefinedOptions(isolate, symbol);
-  ScriptOrigin origin(isolate,
-                      filename,
+  ScriptOrigin origin(filename,
                       0,               // line offset
                       0,               // column offset
                       true,            // is cross origin
