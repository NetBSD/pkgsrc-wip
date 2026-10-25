$NetBSD$

* Backport: https://github.com/mscdex/ssh2/commit/45522bb8723d8ecf459a1d222086e56074c11682
crypto: use more direct Isolate retrieval
GetIsolate() is removed in recent versions of V8

--- node_modules/ssh2/lib/protocol/crypto/src/binding.cc.orig	2026-10-24 14:36:32.224653000 +0000
+++ node_modules/ssh2/lib/protocol/crypto/src/binding.cc
@@ -86,7 +86,7 @@ class ChaChaPolyCipher : public ObjectWr
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -420,7 +420,7 @@ class AESGCMCipher : public ObjectWrap {
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -661,7 +661,7 @@ class GenericCipher : public ObjectWrap 
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -1058,7 +1058,7 @@ class ChaChaPolyDecipher : public Object
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -1486,7 +1486,7 @@ class AESGCMDecipher : public ObjectWrap
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
@@ -1738,7 +1738,7 @@ class GenericDecipher : public ObjectWra
 
     Local<Function> func = Nan::GetFunction(tpl).ToLocalChecked();
     Local<Context> context = Nan::GetCurrentContext();
-    v8::Isolate* isolate = context->GetIsolate();
+    v8::Isolate* isolate = v8::Isolate::GetCurrent();
 
     constructor().Set(isolate, func);
 
