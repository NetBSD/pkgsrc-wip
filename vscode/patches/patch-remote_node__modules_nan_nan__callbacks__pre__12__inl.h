$NetBSD$

* Fiy snapshot usage

--- remote/node_modules/nan/nan_callbacks_pre_12_inl.h.orig	2026-10-24 14:37:41.009523000 +0000
+++ remote/node_modules/nan/nan_callbacks_pre_12_inl.h
@@ -287,6 +287,10 @@ class PropertyCallbackInfo<v8::Integer> 
   }
 };
 
+inline void* GetExternalValue(v8::Local<v8::External> ext) {
+  return ext->Value();
+}
+
 namespace imp {
 template<typename T>
 class ReturnValueImp : public ReturnValue<T> {
