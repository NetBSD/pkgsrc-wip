$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/module_wrap.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/module_wrap.h
@@ -8,6 +8,7 @@
 #include <unordered_map>
 #include <vector>
 #include "base_object.h"
+#include "node.h"
 #include "v8-script.h"
 
 namespace node {
@@ -33,7 +34,14 @@ enum HostDefinedOptions : int {
   kLength = 9,
 };
 
-class ModuleWrap : public BaseObject {
+NODE_EXTERN v8::MaybeLocal<v8::Promise> ImportModuleDynamically(
+    v8::Local<v8::Context> context,
+    v8::Local<v8::Data> host_defined_options,
+    v8::Local<v8::Value> resource_name,
+    v8::Local<v8::String> specifier,
+    v8::Local<v8::FixedArray> import_assertions);
+
+class NODE_EXTERN ModuleWrap : public BaseObject {
  public:
   enum InternalFields {
     kModuleSlot = BaseObject::kInternalFieldCount,
@@ -90,6 +98,8 @@ class ModuleWrap : public BaseObject {
   static void CreateRequiredModuleFacade(
       const v8::FunctionCallbackInfo<v8::Value>& args);
 
+  static ModuleWrap* GetFromModule(node::Environment*, v8::Local<v8::Module>);
+
  private:
   ModuleWrap(Realm* realm,
              v8::Local<v8::Object> object,
@@ -128,7 +138,6 @@ class ModuleWrap : public BaseObject {
       v8::Local<v8::String> specifier,
       v8::Local<v8::FixedArray> import_attributes,
       v8::Local<v8::Module> referrer);
-  static ModuleWrap* GetFromModule(node::Environment*, v8::Local<v8::Module>);
 
   v8::Global<v8::Module> module_;
   std::unordered_map<std::string, v8::Global<v8::Object>> resolve_cache_;
