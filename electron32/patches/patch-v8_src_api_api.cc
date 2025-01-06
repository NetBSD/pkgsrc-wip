$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/api/api.cc.orig	2024-10-18 12:48:35.116423600 +0000
+++ v8/src/api/api.cc
@@ -148,7 +148,7 @@
 #include "src/wasm/wasm-serialization.h"
 #endif  // V8_ENABLE_WEBASSEMBLY
 
-#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 #include <signal.h>
 #include <unistd.h>
 
@@ -6372,14 +6372,33 @@ Local<Data> v8::Object::SlowGetInternalF
       isolate);
 }
 
-void v8::Object::SetInternalField(int index, v8::Local<Data> value) {
-  auto obj = Utils::OpenDirectHandle(this);
+template<typename T>
+void SetInternalFieldImpl(v8::Object* receiver, int index, v8::Local<T> value) {
+  auto obj = Utils::OpenDirectHandle(receiver);
   const char* location = "v8::Object::SetInternalField()";
   if (!InternalFieldOK(obj, index, location)) return;
   auto val = Utils::OpenDirectHandle(*value);
   i::Cast<i::JSObject>(obj)->SetEmbedderField(index, *val);
 }
 
+void v8::Object::SetInternalField(int index, v8::Local<Data> value) {
+  SetInternalFieldImpl(this, index, value);
+}
+
+/**
+ * These are Node.js-specific extentions used to avoid breaking changes in
+ * Node.js v20.x.
+ */
+void v8::Object::SetInternalFieldForNodeCore(int index,
+                                             v8::Local<Module> value) {
+  SetInternalFieldImpl(this, index, value);
+}
+
+void v8::Object::SetInternalFieldForNodeCore(int index,
+                                             v8::Local<UnboundScript> value) {
+  SetInternalFieldImpl(this, index, value);
+}
+
 void* v8::Object::SlowGetAlignedPointerFromInternalField(v8::Isolate* isolate,
                                                          int index) {
   auto obj = Utils::OpenDirectHandle(this);
@@ -6511,7 +6530,7 @@ bool v8::V8::Initialize(const int build_
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD|| V8_OS_NETBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_ENABLE_WEBASSEMBLY && V8_TRAP_HANDLER_SUPPORTED
