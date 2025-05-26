$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node.h
@@ -22,6 +22,12 @@
 #ifndef SRC_NODE_H_
 #define SRC_NODE_H_
 
+#ifdef ELECTRON_ENSURE_CONFIG_GYPI
+#ifndef USING_ELECTRON_CONFIG_GYPI
+#error "It looks like you are building this native module without using the right config.gypi.  This normally means that you need to update electron-rebuild (>=3.2.8) or node-gyp (>=9.0.0) if you're building modules directly."
+#endif
+#endif
+
 #ifdef _WIN32
 # ifndef BUILDING_NODE_EXTENSION
 #  define NODE_EXTERN __declspec(dllexport)
@@ -1546,24 +1552,14 @@ void RegisterSignalHandler(int signal,
                            bool reset_handler = false);
 #endif  // _WIN32
 
-// Configure the layout of the JavaScript object with a cppgc::GarbageCollected
-// instance so that when the JavaScript object is reachable, the garbage
-// collected instance would have its Trace() method invoked per the cppgc
-// contract. To make it work, the process must have called
-// cppgc::InitializeProcess() before, which is usually the case for addons
-// loaded by the stand-alone Node.js executable. Embedders of Node.js can use
-// either need to call it themselves or make sure that
-// ProcessInitializationFlags::kNoInitializeCppgc is *not* set for cppgc to
-// work.
-// If the CppHeap is owned by Node.js, which is usually the case for addon,
-// the object must be created with at least two internal fields available,
-// and the first two internal fields would be configured by Node.js.
-// This may be superseded by a V8 API in the future, see
-// https://bugs.chromium.org/p/v8/issues/detail?id=13960. Until then this
-// serves as a helper for Node.js isolates.
-NODE_EXTERN void SetCppgcReference(v8::Isolate* isolate,
-                                   v8::Local<v8::Object> object,
-                                   void* wrappable);
+// This is kept as a compatibility layer for addons to wrap cppgc-managed
+// objects on Node.js versions without v8::Object::Wrap(). Addons created to
+// work with only Node.js versions with v8::Object::Wrap() should use that
+// instead.
+NODE_DEPRECATED("Use v8::Object::Wrap()",
+                NODE_EXTERN void SetCppgcReference(v8::Isolate* isolate,
+                                                   v8::Local<v8::Object> object,
+                                                   void* wrappable));
 
 }  // namespace node
 
