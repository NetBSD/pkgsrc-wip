$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/converter.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/converter.cc
@@ -20,6 +20,7 @@
 #include "v8/include/v8-value.h"
 
 using v8::ArrayBuffer;
+using v8::ArrayBufferView;
 using v8::External;
 using v8::Function;
 using v8::Int32;
@@ -246,6 +247,20 @@ bool Converter<Local<ArrayBuffer>>::From
   return true;
 }
 
+Local<Value> Converter<Local<ArrayBufferView>>::ToV8(Isolate* isolate,
+                                                 Local<ArrayBufferView> val) {
+  return val.As<Value>();
+}
+
+bool Converter<Local<ArrayBufferView>>::FromV8(Isolate* isolate,
+                                           Local<Value> val,
+                                           Local<ArrayBufferView>* out) {
+  if (!val->IsArrayBufferView())
+    return false;
+  *out = Local<ArrayBufferView>::Cast(val);
+  return true;
+}
+
 Local<Value> Converter<Local<External>>::ToV8(Isolate* isolate,
                                               Local<External> val) {
   return val.As<Value>();
