$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/base_object.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/base_object.h
@@ -111,12 +111,9 @@ class BaseObject : public MemoryRetainer
 
   // Setter/Getter pair for internal fields that can be passed to SetAccessor.
   template <int Field>
-  static void InternalFieldGet(v8::Local<v8::String> property,
-                               const v8::PropertyCallbackInfo<v8::Value>& info);
+  static void InternalFieldGet(const v8::FunctionCallbackInfo<v8::Value>& args);
   template <int Field, bool (v8::Value::*typecheck)() const>
-  static void InternalFieldSet(v8::Local<v8::String> property,
-                               v8::Local<v8::Value> value,
-                               const v8::PropertyCallbackInfo<void>& info);
+  static void InternalFieldSet(const v8::FunctionCallbackInfo<v8::Value>& args);
 
   // This is a bit of a hack. See the override in async_wrap.cc for details.
   virtual bool IsDoneInitializing() const;
