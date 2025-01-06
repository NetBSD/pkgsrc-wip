$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/stream_base.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/stream_base.cc
@@ -492,6 +492,29 @@ Local<Object> StreamBase::GetObject() {
   return GetAsyncWrap()->object();
 }
 
+void StreamBase::AddAccessor(v8::Isolate* isolate,
+                             v8::Local<v8::Signature> signature,
+                             enum v8::PropertyAttribute attributes,
+                             v8::Local<v8::FunctionTemplate> t,
+                             JSMethodFunction* getter,
+                             JSMethodFunction* setter,
+                             v8::Local<v8::String> string) {
+  Local<FunctionTemplate> getter_templ =
+      NewFunctionTemplate(isolate,
+                          getter,
+                          signature,
+                          ConstructorBehavior::kThrow,
+                          SideEffectType::kHasNoSideEffect);
+  Local<FunctionTemplate> setter_templ =
+      NewFunctionTemplate(isolate,
+                          setter,
+                          signature,
+                          ConstructorBehavior::kThrow,
+                          SideEffectType::kHasSideEffect);
+  t->PrototypeTemplate()->SetAccessorProperty(
+      string, getter_templ, setter_templ, attributes);
+}
+
 void StreamBase::AddMethod(Isolate* isolate,
                            Local<Signature> signature,
                            enum PropertyAttribute attributes,
@@ -561,11 +584,14 @@ void StreamBase::AddMethods(IsolateData*
                  JSMethod<&StreamBase::WriteString<LATIN1>>);
   t->PrototypeTemplate()->Set(FIXED_ONE_BYTE_STRING(isolate, "isStreamBase"),
                               True(isolate));
-  t->PrototypeTemplate()->SetAccessor(
-      FIXED_ONE_BYTE_STRING(isolate, "onread"),
-      BaseObject::InternalFieldGet<StreamBase::kOnReadFunctionField>,
-      BaseObject::InternalFieldSet<StreamBase::kOnReadFunctionField,
-                                   &Value::IsFunction>);
+  AddAccessor(isolate,
+              sig,
+              static_cast<PropertyAttribute>(DontDelete | DontEnum),
+              t,
+              BaseObject::InternalFieldGet<StreamBase::kOnReadFunctionField>,
+              BaseObject::InternalFieldSet<StreamBase::kOnReadFunctionField,
+                                           &Value::IsFunction>,
+              FIXED_ONE_BYTE_STRING(isolate, "onread"));
 }
 
 void StreamBase::RegisterExternalReferences(
