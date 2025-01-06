$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/wasm/wasm-js.cc.orig	2024-10-18 12:48:35.504421200 +0000
+++ v8/src/wasm/wasm-js.cc
@@ -1314,9 +1314,12 @@ i::Handle<i::HeapObject> DefaultReferenc
   DCHECK(type.is_object_reference());
   // Use undefined for JS type (externref) but null for wasm types as wasm does
   // not know undefined.
-  if (type.heap_representation() == i::wasm::HeapType::kExtern ||
-      type.heap_representation() == i::wasm::HeapType::kNoExtern) {
+  if (type.heap_representation() == i::wasm::HeapType::kExtern) {
     return isolate->factory()->undefined_value();
+  } else if (type.heap_representation() == i::wasm::HeapType::kNoExtern ||
+             type.heap_representation() == i::wasm::HeapType::kExn ||
+             type.heap_representation() == i::wasm::HeapType::kNoExn) {
+    return isolate->factory()->null_value();
   }
   return isolate->factory()->wasm_null();
 }
