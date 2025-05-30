$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/nan_callbacks_12_inl.h.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/nan_callbacks_12_inl.h
@@ -255,7 +255,98 @@ typedef void (*NativeSetter)(
   , const v8::PropertyCallbackInfo<void> &);
 #endif
 
-#if NODE_MODULE_VERSION > NODE_0_12_MODULE_VERSION
+#if NODE_MODULE_VERSION > NODE_21_0_MODULE_VERSION
+static
+v8::Intercepted PropertyGetterCallbackWrapper(
+    v8::Local<v8::Name> property
+  , const v8::PropertyCallbackInfo<v8::Value> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Value>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  PropertyGetterCallback callback = reinterpret_cast<PropertyGetterCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(property.As<v8::String>(), cbinfo);
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativePropertyGetter)
+    (v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value> &);
+
+static
+v8::Intercepted PropertySetterCallbackWrapper(
+    v8::Local<v8::Name> property
+  , v8::Local<v8::Value> value
+  , const v8::PropertyCallbackInfo<void> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<void>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  PropertySetterCallback callback = reinterpret_cast<PropertySetterCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(property.As<v8::String>(), value, *reinterpret_cast<PropertyCallbackInfo<v8::Value>*>(&cbinfo));
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativePropertySetter)(
+    v8::Local<v8::Name>
+  , v8::Local<v8::Value>
+  , const v8::PropertyCallbackInfo<void> &);
+
+static
+void PropertyEnumeratorCallbackWrapper(
+    const v8::PropertyCallbackInfo<v8::Array> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Array>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  PropertyEnumeratorCallback callback =
+      reinterpret_cast<PropertyEnumeratorCallback>(reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kPropertyEnumeratorIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(cbinfo);
+}
+
+typedef void (*NativePropertyEnumerator)
+    (const v8::PropertyCallbackInfo<v8::Array> &);
+
+static
+v8::Intercepted PropertyDeleterCallbackWrapper(
+    v8::Local<v8::Name> property
+  , const v8::PropertyCallbackInfo<v8::Boolean> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Boolean>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  PropertyDeleterCallback callback = reinterpret_cast<PropertyDeleterCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(property.As<v8::String>(), cbinfo);
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (NativePropertyDeleter)
+    (v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Boolean> &);
+
+static
+v8::Intercepted PropertyQueryCallbackWrapper(
+    v8::Local<v8::Name> property
+  , const v8::PropertyCallbackInfo<v8::Integer> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Integer>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  PropertyQueryCallback callback = reinterpret_cast<PropertyQueryCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(property.As<v8::String>(), cbinfo);
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativePropertyQuery)
+    (v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Integer> &);
+#elif NODE_MODULE_VERSION > NODE_0_12_MODULE_VERSION
 static
 void PropertyGetterCallbackWrapper(
     v8::Local<v8::Name> property
@@ -431,6 +522,96 @@ typedef void (*NativePropertyQuery)
     (v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Integer> &);
 #endif
 
+#if NODE_MODULE_VERSION > NODE_21_0_MODULE_VERSION
+static
+v8::Intercepted IndexGetterCallbackWrapper(
+    uint32_t index, const v8::PropertyCallbackInfo<v8::Value> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Value>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  IndexGetterCallback callback = reinterpret_cast<IndexGetterCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kIndexPropertyGetterIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(index, cbinfo);
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativeIndexGetter)
+    (uint32_t, const v8::PropertyCallbackInfo<v8::Value> &);
+
+static
+v8::Intercepted IndexSetterCallbackWrapper(
+    uint32_t index
+  , v8::Local<v8::Value> value
+  , const v8::PropertyCallbackInfo<void> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<void>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  IndexSetterCallback callback = reinterpret_cast<IndexSetterCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kIndexPropertySetterIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(index, value, *reinterpret_cast<PropertyCallbackInfo<v8::Value>*>(&cbinfo));
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativeIndexSetter)(
+    uint32_t
+  , v8::Local<v8::Value>
+  , const v8::PropertyCallbackInfo<void> &);
+
+static
+void IndexEnumeratorCallbackWrapper(
+    const v8::PropertyCallbackInfo<v8::Array> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Array>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  IndexEnumeratorCallback callback = reinterpret_cast<IndexEnumeratorCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(
+              kIndexPropertyEnumeratorIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(cbinfo);
+}
+
+typedef void (*NativeIndexEnumerator)
+    (const v8::PropertyCallbackInfo<v8::Array> &);
+
+static
+v8::Intercepted IndexDeleterCallbackWrapper(
+    uint32_t index, const v8::PropertyCallbackInfo<v8::Boolean> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Boolean>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  IndexDeleterCallback callback = reinterpret_cast<IndexDeleterCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kIndexPropertyDeleterIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(index, cbinfo);
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativeIndexDeleter)
+    (uint32_t, const v8::PropertyCallbackInfo<v8::Boolean> &);
+
+static
+v8::Intercepted IndexQueryCallbackWrapper(
+    uint32_t index, const v8::PropertyCallbackInfo<v8::Integer> &info) {
+  v8::Local<v8::Object> obj = info.Data().As<v8::Object>();
+  PropertyCallbackInfo<v8::Integer>
+      cbinfo(info, obj->GetInternalField(kDataIndex).As<v8::Value>());
+  IndexQueryCallback callback = reinterpret_cast<IndexQueryCallback>(
+      reinterpret_cast<intptr_t>(
+          obj->GetInternalField(kIndexPropertyQueryIndex)
+              .As<v8::Value>().As<v8::External>()->Value()));
+  callback(index, cbinfo);
+  return v8::Intercepted::kYes;
+}
+
+typedef v8::Intercepted (*NativeIndexQuery)
+    (uint32_t, const v8::PropertyCallbackInfo<v8::Integer> &);
+#else
 static
 void IndexGetterCallbackWrapper(
     uint32_t index, const v8::PropertyCallbackInfo<v8::Value> &info) {
@@ -515,6 +696,8 @@ void IndexQueryCallbackWrapper(
 
 typedef void (*NativeIndexQuery)
     (uint32_t, const v8::PropertyCallbackInfo<v8::Integer> &);
+#endif
+
 }  // end of namespace imp
 
 #endif  // NAN_CALLBACKS_12_INL_H_
