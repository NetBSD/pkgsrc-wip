$NetBSD$

--- third_party/pdfium/fxjs/cjs_runtime.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ third_party/pdfium/fxjs/cjs_runtime.cpp
@@ -226,7 +226,7 @@ v8::Local<v8::Value> CJS_Runtime::MaybeC
     return value;
 
   v8::Local<v8::Number> num = maybeNum.ToLocalChecked();
-  if (std::isnan(num->Value()) && !bAllowNaN)
+  if (isnan(num->Value()) && !bAllowNaN)
     return value;
 
   return num;
