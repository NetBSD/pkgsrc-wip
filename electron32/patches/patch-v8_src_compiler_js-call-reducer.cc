$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/js-call-reducer.cc.orig	2024-10-18 12:48:35.244422700 +0000
+++ v8/src/compiler/js-call-reducer.cc
@@ -3787,14 +3787,13 @@ bool CanInlineJSToWasmCall(const wasm::F
     return false;
   }
 
-  wasm::ValueType externRefNonNull = wasm::kWasmExternRef.AsNonNull();
   for (auto type : wasm_signature->all()) {
 #if defined(V8_TARGET_ARCH_32_BIT)
     if (type == wasm::kWasmI64) return false;
 #endif
     if (type != wasm::kWasmI32 && type != wasm::kWasmI64 &&
         type != wasm::kWasmF32 && type != wasm::kWasmF64 &&
-        type != wasm::kWasmExternRef && type != externRefNonNull) {
+        type != wasm::kWasmExternRef) {
       return false;
     }
   }
