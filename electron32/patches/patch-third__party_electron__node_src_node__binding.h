$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_binding.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_binding.h
@@ -137,6 +137,8 @@ void GetInternalBinding(const v8::Functi
 void GetLinkedBinding(const v8::FunctionCallbackInfo<v8::Value>& args);
 void DLOpen(const v8::FunctionCallbackInfo<v8::Value>& args);
 
+NODE_EXTERN node_module* get_linked_module(const char *name);
+
 }  // namespace binding
 
 }  // namespace node
