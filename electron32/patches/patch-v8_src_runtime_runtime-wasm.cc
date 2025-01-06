$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/runtime/runtime-wasm.cc.orig	2024-10-18 12:48:35.456421400 +0000
+++ v8/src/runtime/runtime-wasm.cc
@@ -626,9 +626,23 @@ RUNTIME_FUNCTION(Runtime_TierUpWasmToJSW
   Handle<WasmTrustedInstanceData> trusted_data(ref->instance_data(), isolate);
   if (IsTuple2(*origin)) {
     auto tuple = Cast<Tuple2>(origin);
-    trusted_data =
-        handle(Cast<WasmInstanceObject>(tuple->value1())->trusted_data(isolate),
-               isolate);
+    Handle<WasmTrustedInstanceData> call_origin_trusted_data(
+        Cast<WasmInstanceObject>(tuple->value1())->trusted_data(isolate),
+        isolate);
+    // TODO(371565065): We do not tier up the wrapper if the JS function wasn't
+    // imported in the current instance but the signature is specific to the
+    // importing instance. Remove this bailout again.
+    if (trusted_data->module() != call_origin_trusted_data->module()) {
+      for (wasm::ValueType type : sig.all()) {
+        if (type.has_index()) {
+          // Reset the tiering budget, so that we don't have to deal with the
+          // underflow.
+          ref->set_wrapper_budget(Smi::kMaxValue);
+          return ReadOnlyRoots(isolate).undefined_value();
+        }
+      }
+    }
+    trusted_data = call_origin_trusted_data;
     origin = direct_handle(tuple->value2(), isolate);
   }
   const wasm::WasmModule* module = trusted_data->module();
