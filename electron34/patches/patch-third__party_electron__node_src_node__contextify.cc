$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_contextify.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_contextify.cc
@@ -51,6 +51,7 @@ using v8::FunctionTemplate;
 using v8::HandleScope;
 using v8::IndexedPropertyHandlerConfiguration;
 using v8::Int32;
+using v8::Intercepted;
 using v8::Isolate;
 using v8::Just;
 using v8::Local;
@@ -485,16 +486,20 @@ bool ContextifyContext::IsStillInitializ
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
@@ -504,22 +509,31 @@ void ContextifyContext::PropertyGetterCa
 
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
@@ -537,8 +551,9 @@ void ContextifyContext::PropertySetterCa
       (static_cast<int>(attributes) &
       static_cast<int>(PropertyAttribute::ReadOnly));
 
-  if (read_only)
-    return;
+  if (read_only) {
+    return Intercepted::kNo;
+  }
 
   // true for x = 5
   // false for this.x = 5
@@ -557,11 +572,16 @@ void ContextifyContext::PropertySetterCa
 
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
@@ -575,19 +595,23 @@ void ContextifyContext::PropertySetterCa
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
 
@@ -597,19 +621,23 @@ void ContextifyContext::PropertyDescript
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
@@ -628,7 +656,7 @@ void ContextifyContext::PropertyDefinerC
   // If the property is set on the global as neither writable nor
   // configurable, don't change it on the global or sandbox.
   if (is_declared && read_only && dont_delete) {
-    return;
+    return Intercepted::kNo;
   }
 
   Local<Object> sandbox = ctx->sandbox();
@@ -651,6 +679,9 @@ void ContextifyContext::PropertyDefinerC
         desc.has_set() ? desc.set() : Undefined(isolate).As<Value>());
 
     define_prop_on_sandbox(&desc_for_sandbox);
+    // TODO(https://github.com/nodejs/node/issues/52634): this should return
+    // kYes to behave according to the expected semantics.
+    return Intercepted::kNo;
   } else {
     Local<Value> value =
         desc.has_value() ? desc.value() : Undefined(isolate).As<Value>();
@@ -662,26 +693,32 @@ void ContextifyContext::PropertyDefinerC
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
@@ -701,76 +738,84 @@ void ContextifyContext::PropertyEnumerat
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
@@ -870,8 +915,7 @@ void ContextifyScript::New(const Functio
   host_defined_options->Set(
       isolate, loader::HostDefinedOptions::kID, id_symbol);
 
-  ScriptOrigin origin(isolate,
-                      filename,
+  ScriptOrigin origin(filename,
                       line_offset,                          // line offset
                       column_offset,                        // column offset
                       true,                                 // is cross origin
@@ -991,7 +1035,7 @@ MaybeLocal<Function> CompileFunction(Loc
                                      Local<String> filename,
                                      Local<String> content,
                                      std::vector<Local<String>>* parameters) {
-  ScriptOrigin script_origin(context->GetIsolate(), filename, 0, 0, true);
+  ScriptOrigin script_origin(filename, 0, 0, true);
   ScriptCompiler::Source script_source(content, script_origin);
 
   return ScriptCompiler::CompileFunction(context,
@@ -1101,7 +1145,6 @@ bool ContextifyScript::EvalMachine(Local
   }
 
   TryCatchScope try_catch(env);
-  Isolate::SafeForTerminationScope safe_for_termination(env->isolate());
   ContextifyScript* wrapped_script;
   ASSIGN_OR_RETURN_UNWRAP(&wrapped_script, args.This(), false);
   Local<UnboundScript> unbound_script =
@@ -1270,8 +1313,7 @@ void ContextifyContext::CompileFunction(
   Local<PrimitiveArray> host_defined_options =
       loader::ModuleWrap::GetHostDefinedOptions(isolate, id_symbol);
 
-  ScriptOrigin origin(isolate,
-                      filename,
+  ScriptOrigin origin(filename,
                       line_offset,     // line offset
                       column_offset,   // column offset
                       true,            // is cross origin
@@ -1458,8 +1500,7 @@ static MaybeLocal<Function> CompileFunct
   Local<Symbol> symbol = env->vm_dynamic_import_default_internal();
   Local<PrimitiveArray> hdo =
       loader::ModuleWrap::GetHostDefinedOptions(isolate, symbol);
-  ScriptOrigin origin(isolate,
-                      filename,
+  ScriptOrigin origin(filename,
                       0,               // line offset
                       0,               // column offset
                       true,            // is cross origin
