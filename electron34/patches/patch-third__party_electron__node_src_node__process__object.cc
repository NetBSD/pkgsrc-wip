$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_process_object.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_process_object.cc
@@ -13,7 +13,6 @@
 
 namespace node {
 using v8::Context;
-using v8::DEFAULT;
 using v8::EscapableHandleScope;
 using v8::Function;
 using v8::FunctionCallbackInfo;
@@ -188,13 +187,12 @@ void PatchProcessObject(const FunctionCa
 
   // process.title
   CHECK(process
-            ->SetAccessor(
+            ->SetNativeDataProperty(
                 context,
                 FIXED_ONE_BYTE_STRING(isolate, "title"),
                 ProcessTitleGetter,
                 env->owns_process_state() ? ProcessTitleSetter : nullptr,
                 Local<Value>(),
-                DEFAULT,
                 None,
                 SideEffectType::kHasNoSideEffect)
             .FromJust());
@@ -213,9 +211,15 @@ void PatchProcessObject(const FunctionCa
   READONLY_PROPERTY(process, "pid",
                     Integer::New(isolate, uv_os_getpid()));
 
-  CHECK(process->SetAccessor(context,
-                             FIXED_ONE_BYTE_STRING(isolate, "ppid"),
-                             GetParentProcessId).FromJust());
+  CHECK(process
+            ->SetNativeDataProperty(context,
+                                    FIXED_ONE_BYTE_STRING(isolate, "ppid"),
+                                    GetParentProcessId,
+                                    nullptr,
+                                    Local<Value>(),
+                                    None,
+                                    SideEffectType::kHasNoSideEffect)
+            .FromJust());
 
   // --security-revert flags
 #define V(code, _, __)                                                        \
@@ -240,12 +244,15 @@ void PatchProcessObject(const FunctionCa
 
   // process.debugPort
   CHECK(process
-            ->SetAccessor(context,
-                          FIXED_ONE_BYTE_STRING(isolate, "debugPort"),
-                          DebugPortGetter,
-                          env->owns_process_state() ? DebugPortSetter : nullptr,
-                          Local<Value>())
-            .FromJust());
+            ->SetNativeDataProperty(
+                context,
+                FIXED_ONE_BYTE_STRING(isolate, "debugPort"),
+                DebugPortGetter,
+                env->owns_process_state() ? DebugPortSetter : nullptr,
+                Local<Value>(),
+                None,
+                SideEffectType::kHasNoSideEffect)
+             .FromJust());
 
   // process.versions
   Local<Object> versions = Object::New(isolate);
