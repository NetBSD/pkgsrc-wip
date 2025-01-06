$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/converter.h.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/converter.h
@@ -191,6 +191,15 @@ struct GIN_EXPORT Converter<v8::Local<v8
 };
 
 template<>
+struct GIN_EXPORT Converter<v8::Local<v8::ArrayBufferView> > {
+  static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
+                                    v8::Local<v8::ArrayBufferView> val);
+  static bool FromV8(v8::Isolate* isolate,
+                     v8::Local<v8::Value> val,
+                     v8::Local<v8::ArrayBufferView>* out);
+};
+
+template<>
 struct GIN_EXPORT Converter<v8::Local<v8::External> > {
   static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
                                     v8::Local<v8::External> val);
