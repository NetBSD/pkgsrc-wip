$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/env.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/env.h
@@ -49,7 +49,7 @@
 #include "uv.h"
 #include "v8.h"
 
-#if HAVE_OPENSSL
+#if HAVE_OPENSSL && OPENSSL_VERSION_MAJOR >= 3
 #include <openssl/evp.h>
 #endif
 
@@ -174,10 +174,6 @@ class NODE_EXTERN_PRIVATE IsolateData : 
   uint16_t* embedder_id_for_cppgc() const;
   uint16_t* embedder_id_for_non_cppgc() const;
 
-  static inline void SetCppgcReference(v8::Isolate* isolate,
-                                       v8::Local<v8::Object> object,
-                                       void* wrappable);
-
   inline uv_loop_t* event_loop() const;
   inline MultiIsolatePlatform* platform() const;
   inline const SnapshotData* snapshot_data() const;
@@ -1051,7 +1047,7 @@ class Environment : public MemoryRetaine
     kExitInfoFieldCount
   };
 
-#if HAVE_OPENSSL
+#if HAVE_OPENSSL// && !defined(OPENSSL_IS_BORINGSSL)
 #if OPENSSL_VERSION_MAJOR >= 3
   // We declare another alias here to avoid having to include crypto_util.h
   using EVPMDPointer = DeleteFnPtr<EVP_MD, EVP_MD_free>;
