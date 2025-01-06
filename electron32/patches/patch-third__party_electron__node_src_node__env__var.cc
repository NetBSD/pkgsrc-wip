$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_env_var.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_env_var.cc
@@ -16,6 +16,7 @@ using v8::DontEnum;
 using v8::FunctionTemplate;
 using v8::HandleScope;
 using v8::Integer;
+using v8::Intercepted;
 using v8::Isolate;
 using v8::Just;
 using v8::Local;
@@ -336,24 +337,27 @@ Maybe<bool> KVStore::AssignToObject(v8::
   return Just(true);
 }
 
-static void EnvGetter(Local<Name> property,
-                      const PropertyCallbackInfo<Value>& info) {
+static Intercepted EnvGetter(Local<Name> property,
+                             const PropertyCallbackInfo<Value>& info) {
   Environment* env = Environment::GetCurrent(info);
   CHECK(env->has_run_bootstrapping_code());
   if (property->IsSymbol()) {
-    return info.GetReturnValue().SetUndefined();
+    info.GetReturnValue().SetUndefined();
+    return Intercepted::kYes;
   }
   CHECK(property->IsString());
   MaybeLocal<String> value_string =
       env->env_vars()->Get(env->isolate(), property.As<String>());
   if (!value_string.IsEmpty()) {
     info.GetReturnValue().Set(value_string.ToLocalChecked());
+    return Intercepted::kYes;
   }
+  return Intercepted::kNo;
 }
 
-static void EnvSetter(Local<Name> property,
-                      Local<Value> value,
-                      const PropertyCallbackInfo<Value>& info) {
+static Intercepted EnvSetter(Local<Name> property,
+                             Local<Value> value,
+                             const PropertyCallbackInfo<void>& info) {
   Environment* env = Environment::GetCurrent(info);
   CHECK(env->has_run_bootstrapping_code());
   // calling env->EmitProcessEnvWarning() sets a variable indicating that
@@ -369,35 +373,40 @@ static void EnvSetter(Local<Name> proper
             "the "
             "value to a string before setting process.env with it.",
             "DEP0104")
-            .IsNothing())
-      return;
+            .IsNothing()) {
+      return Intercepted::kNo;
+    }
   }
 
   Local<String> key;
   Local<String> value_string;
   if (!property->ToString(env->context()).ToLocal(&key) ||
       !value->ToString(env->context()).ToLocal(&value_string)) {
-    return;
+    return Intercepted::kNo;
   }
 
   env->env_vars()->Set(env->isolate(), key, value_string);
 
-  // Whether it worked or not, always return value.
-  info.GetReturnValue().Set(value);
+  return Intercepted::kYes;
 }
 
-static void EnvQuery(Local<Name> property,
-                     const PropertyCallbackInfo<Integer>& info) {
+static Intercepted EnvQuery(Local<Name> property,
+                            const PropertyCallbackInfo<Integer>& info) {
   Environment* env = Environment::GetCurrent(info);
   CHECK(env->has_run_bootstrapping_code());
   if (property->IsString()) {
     int32_t rc = env->env_vars()->Query(env->isolate(), property.As<String>());
-    if (rc != -1) info.GetReturnValue().Set(rc);
+    if (rc != -1) {
+      // Return attributes for the property.
+      info.GetReturnValue().Set(v8::None);
+      return Intercepted::kYes;
+    }
   }
+  return Intercepted::kNo;
 }
 
-static void EnvDeleter(Local<Name> property,
-                       const PropertyCallbackInfo<Boolean>& info) {
+static Intercepted EnvDeleter(Local<Name> property,
+                              const PropertyCallbackInfo<Boolean>& info) {
   Environment* env = Environment::GetCurrent(info);
   CHECK(env->has_run_bootstrapping_code());
   if (property->IsString()) {
@@ -407,6 +416,7 @@ static void EnvDeleter(Local<Name> prope
   // process.env never has non-configurable properties, so always
   // return true like the tc39 delete operator.
   info.GetReturnValue().Set(true);
+  return Intercepted::kYes;
 }
 
 static void EnvEnumerator(const PropertyCallbackInfo<Array>& info) {
@@ -417,9 +427,9 @@ static void EnvEnumerator(const Property
       env->env_vars()->Enumerate(env->isolate()));
 }
 
-static void EnvDefiner(Local<Name> property,
-                       const PropertyDescriptor& desc,
-                       const PropertyCallbackInfo<Value>& info) {
+static Intercepted EnvDefiner(Local<Name> property,
+                              const PropertyDescriptor& desc,
+                              const PropertyCallbackInfo<void>& info) {
   Environment* env = Environment::GetCurrent(info);
   if (desc.has_value()) {
     if (!desc.has_writable() ||
@@ -430,6 +440,7 @@ static void EnvDefiner(Local<Name> prope
                                                "configurable, writable,"
                                                " and enumerable "
                                                "data descriptor");
+      return Intercepted::kYes;
     } else if (!desc.configurable() ||
                !desc.enumerable() ||
                !desc.writable()) {
@@ -438,6 +449,7 @@ static void EnvDefiner(Local<Name> prope
                                                "configurable, writable,"
                                                " and enumerable "
                                                "data descriptor");
+      return Intercepted::kYes;
     } else {
       return EnvSetter(property, desc.value(), info);
     }
@@ -447,12 +459,14 @@ static void EnvDefiner(Local<Name> prope
                                              "'process.env' does not accept an"
                                              " accessor(getter/setter)"
                                              " descriptor");
+    return Intercepted::kYes;
   } else {
     THROW_ERR_INVALID_OBJECT_DEFINE_PROPERTY(env,
                                              "'process.env' only accepts a "
                                              "configurable, writable,"
                                              " and enumerable "
                                              "data descriptor");
+    return Intercepted::kYes;
   }
 }
 
