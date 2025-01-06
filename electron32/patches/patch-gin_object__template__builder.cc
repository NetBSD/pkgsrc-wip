$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/object_template_builder.cc.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/object_template_builder.cc
@@ -216,6 +216,13 @@ ObjectTemplateBuilder::ObjectTemplateBui
   template_->SetInternalFieldCount(kNumberOfInternalFields);
 }
 
+ObjectTemplateBuilder::ObjectTemplateBuilder(v8::Isolate* isolate,
+                                             const char* type_name,
+                                             v8::Local<v8::ObjectTemplate> tmpl)
+    : isolate_(isolate), type_name_(type_name), template_(tmpl) {
+  template_->SetInternalFieldCount(kNumberOfInternalFields);
+}
+
 ObjectTemplateBuilder::ObjectTemplateBuilder(
     const ObjectTemplateBuilder& other) = default;
 
