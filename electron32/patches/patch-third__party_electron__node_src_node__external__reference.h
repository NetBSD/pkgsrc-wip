$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_external_reference.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_external_reference.h
@@ -64,20 +64,19 @@ class ExternalReferenceRegistry {
   V(CFunctionWithBool)                                                         \
   V(const v8::CFunctionInfo*)                                                  \
   V(v8::FunctionCallback)                                                      \
-  V(v8::AccessorGetterCallback)                                                \
-  V(v8::AccessorSetterCallback)                                                \
   V(v8::AccessorNameGetterCallback)                                            \
   V(v8::AccessorNameSetterCallback)                                            \
-  V(v8::GenericNamedPropertyDefinerCallback)                                   \
-  V(v8::GenericNamedPropertyDeleterCallback)                                   \
-  V(v8::GenericNamedPropertyEnumeratorCallback)                                \
-  V(v8::GenericNamedPropertyQueryCallback)                                     \
-  V(v8::GenericNamedPropertySetterCallback)                                    \
-  V(v8::IndexedPropertySetterCallback)                                         \
-  V(v8::IndexedPropertyDefinerCallback)                                        \
-  V(v8::IndexedPropertyDeleterCallback)                                        \
-  V(v8::IndexedPropertyQueryCallback)                                          \
-  V(v8::IndexedPropertyDescriptorCallback)                                     \
+  V(v8::NamedPropertyGetterCallback)                                           \
+  V(v8::NamedPropertyDefinerCallback)                                          \
+  V(v8::NamedPropertyDeleterCallback)                                          \
+  V(v8::NamedPropertyEnumeratorCallback)                                       \
+  V(v8::NamedPropertyQueryCallback)                                            \
+  V(v8::NamedPropertySetterCallback)                                           \
+  V(v8::IndexedPropertyGetterCallbackV2)                                       \
+  V(v8::IndexedPropertySetterCallbackV2)                                       \
+  V(v8::IndexedPropertyDefinerCallbackV2)                                      \
+  V(v8::IndexedPropertyDeleterCallbackV2)                                      \
+  V(v8::IndexedPropertyQueryCallbackV2)                                        \
   V(const v8::String::ExternalStringResourceBase*)
 
 #define V(ExternalReferenceType)                                               \
