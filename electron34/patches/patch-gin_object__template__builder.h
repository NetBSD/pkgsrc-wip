$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/object_template_builder.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/object_template_builder.h
@@ -46,6 +46,9 @@ class GIN_EXPORT ObjectTemplateBuilder {
  public:
   explicit ObjectTemplateBuilder(v8::Isolate* isolate);
   ObjectTemplateBuilder(v8::Isolate* isolate, const char* type_name);
+  ObjectTemplateBuilder(v8::Isolate* isolate,
+                        const char* type_name,
+                        v8::Local<v8::ObjectTemplate> tmpl);
   ObjectTemplateBuilder(const ObjectTemplateBuilder& other);
   ~ObjectTemplateBuilder();
 
