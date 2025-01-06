$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_options.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_options.cc
@@ -6,7 +6,7 @@
 #include "node_external_reference.h"
 #include "node_internals.h"
 #include "node_sea.h"
-#if HAVE_OPENSSL
+#if HAVE_OPENSSL && !defined(OPENSSL_IS_BORINGSSL)
 #include "openssl/opensslv.h"
 #endif
 
@@ -1405,14 +1405,16 @@ void GetEmbedderOptions(const FunctionCa
   }
   Isolate* isolate = args.GetIsolate();
 
-  constexpr size_t kOptionsSize = 4;
+  constexpr size_t kOptionsSize = 5;
   std::array<Local<Name>, kOptionsSize> names = {
+      FIXED_ONE_BYTE_STRING(env->isolate(), "hasPrepareStackTraceCallback"),
       FIXED_ONE_BYTE_STRING(env->isolate(), "shouldNotRegisterESMLoader"),
       FIXED_ONE_BYTE_STRING(env->isolate(), "noGlobalSearchPaths"),
       FIXED_ONE_BYTE_STRING(env->isolate(), "noBrowserGlobals"),
       FIXED_ONE_BYTE_STRING(env->isolate(), "hasEmbedderPreload")};
 
   std::array<Local<Value>, kOptionsSize> values = {
+      Boolean::New(isolate, env->prepare_stack_trace_callback().IsEmpty()),
       Boolean::New(isolate, env->should_not_register_esm_loader()),
       Boolean::New(isolate, env->no_global_search_paths()),
       Boolean::New(isolate, env->no_browser_globals()),
