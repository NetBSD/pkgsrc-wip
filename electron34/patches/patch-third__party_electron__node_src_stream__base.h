$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/stream_base.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/stream_base.h
@@ -413,6 +413,13 @@ class StreamBase : public StreamResource
   EmitToJSStreamListener default_listener_;
 
   void SetWriteResult(const StreamWriteResult& res);
+  static void AddAccessor(v8::Isolate* isolate,
+                          v8::Local<v8::Signature> sig,
+                          enum v8::PropertyAttribute attributes,
+                          v8::Local<v8::FunctionTemplate> t,
+                          JSMethodFunction* getter,
+                          JSMethodFunction* setter,
+                          v8::Local<v8::String> str);
   static void AddMethod(v8::Isolate* isolate,
                         v8::Local<v8::Signature> sig,
                         enum v8::PropertyAttribute attributes,
