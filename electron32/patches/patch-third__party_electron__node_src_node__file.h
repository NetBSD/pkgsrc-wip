$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_file.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_file.h
@@ -86,13 +86,6 @@ class BindingData : public SnapshotableO
   SERIALIZABLE_OBJECT_METHODS()
   SET_BINDING_ID(fs_binding_data)
 
-  static void LegacyMainResolve(
-      const v8::FunctionCallbackInfo<v8::Value>& args);
-
-  static void CreatePerIsolateProperties(IsolateData* isolate_data,
-                                         v8::Local<v8::ObjectTemplate> ctor);
-  static void RegisterExternalReferences(ExternalReferenceRegistry* registry);
-
   void MemoryInfo(MemoryTracker* tracker) const override;
   SET_SELF_SIZE(BindingData)
   SET_MEMORY_INFO_NAME(BindingData)
