$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/execution/isolate.cc.orig	2024-10-18 12:48:35.308422300 +0000
+++ v8/src/execution/isolate.cc
@@ -159,6 +159,10 @@
 #include "src/execution/simulator-base.h"
 #endif
 
+#if defined(V8_OS_OPENBSD)
+#include <sys/mman.h>
+#endif
+
 extern "C" const uint8_t v8_Default_embedded_blob_code_[];
 extern "C" uint32_t v8_Default_embedded_blob_code_size_;
 extern "C" const uint8_t v8_Default_embedded_blob_data_[];
@@ -2523,6 +2527,13 @@ HandlerTable::CatchPrediction PredictExc
 
 HandlerTable::CatchPrediction PredictException(const FrameSummary& summary,
                                                Isolate* isolate) {
+  if (!summary.IsJavaScript()) {
+    // This can happen when WASM is inlined by TurboFan. For now we ignore
+    // frames that are not JavaScript.
+    // TODO(https://crbug.com/349588762): We should also check Wasm code
+    // for exception handling.
+    return HandlerTable::UNCAUGHT;
+  }
   PtrComprCageBase cage_base(isolate);
   DirectHandle<AbstractCode> code = summary.AsJavaScript().abstract_code();
   if (code->kind(cage_base) == CodeKind::BUILTIN) {
@@ -4829,6 +4840,13 @@ void Isolate::InitializeDefaultEmbeddedB
   const uint8_t* data = DefaultEmbeddedBlobData();
   uint32_t data_size = DefaultEmbeddedBlobDataSize();
 
+#if defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  if (code_size > 0) {
+    mprotect(reinterpret_cast<void *>(const_cast<uint8_t *>(code)),
+            code_size, PROT_READ | PROT_EXEC);
+  }
+#endif
+
   if (StickyEmbeddedBlobCode() != nullptr) {
     base::MutexGuard guard(current_embedded_blob_refcount_mutex_.Pointer());
     // Check again now that we hold the lock.
