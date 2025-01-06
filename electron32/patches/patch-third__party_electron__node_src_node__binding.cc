$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_binding.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_binding.cc
@@ -4,6 +4,7 @@
 #include "node_builtins.h"
 #include "node_errors.h"
 #include "node_external_reference.h"
+#include "node_process.h"
 #include "util.h"
 
 #include <string>
@@ -483,7 +484,12 @@ void DLOpen(const FunctionCallbackInfo<V
       if (mp->nm_context_register_func == nullptr) {
         if (env->force_context_aware()) {
           dlib->Close();
-          THROW_ERR_NON_CONTEXT_AWARE_DISABLED(env);
+          char errmsg[1024];
+          snprintf(errmsg,
+                   sizeof(errmsg),
+                   "Loading non-context-aware native module in renderer: '%s'. See https://github.com/electron/electron/issues/18397.",
+                   *filename);
+          env->ThrowError(errmsg);
           return false;
         }
       }
@@ -641,6 +647,10 @@ void GetInternalBinding(const FunctionCa
   args.GetReturnValue().Set(exports);
 }
 
+node_module* get_linked_module(const char* name) {
+  return FindModule(modlist_linked, name, NM_F_LINKED);
+}
+
 void GetLinkedBinding(const FunctionCallbackInfo<Value>& args) {
   Environment* env = Environment::GetCurrent(args);
 
