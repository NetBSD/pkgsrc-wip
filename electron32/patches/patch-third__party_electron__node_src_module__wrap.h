$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/module_wrap.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/module_wrap.h
@@ -7,6 +7,7 @@
 #include <string>
 #include <vector>
 #include "base_object.h"
+#include "node.h"
 
 namespace node {
 
@@ -31,7 +32,14 @@ enum HostDefinedOptions : int {
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
@@ -68,6 +76,8 @@ class ModuleWrap : public BaseObject {
     return true;
   }
 
+  static ModuleWrap* GetFromModule(node::Environment*, v8::Local<v8::Module>);
+
  private:
   ModuleWrap(Realm* realm,
              v8::Local<v8::Object> object,
@@ -110,7 +120,6 @@ class ModuleWrap : public BaseObject {
       v8::Local<v8::String> specifier,
       v8::Local<v8::FixedArray> import_attributes,
       v8::Local<v8::Module> referrer);
-  static ModuleWrap* GetFromModule(node::Environment*, v8::Local<v8::Module>);
 
   v8::Global<v8::Module> module_;
   std::unordered_map<std::string, v8::Global<v8::Promise>> resolve_cache_;
