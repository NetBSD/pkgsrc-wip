$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/test/mjsunit/regress/wasm/regress-366635354.js.orig	2025-02-15 18:06:05.621191360 +0000
+++ v8/test/mjsunit/regress/wasm/regress-366635354.js
@@ -0,0 +1,32 @@
+// Copyright 2024 the V8 project authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// Flags: --always-turbofan --allow-natives-syntax
+
+d8.file.execute('test/mjsunit/wasm/wasm-module-builder.js');
+
+let builder = new WasmModuleBuilder();
+builder.addFunction('foo', makeSig([wasmRefType(kWasmExternRef)], []))
+    .addBody([kExprUnreachable])
+    .exportFunc();
+let instance = builder.instantiate();
+const wasm_caller = () => instance.exports.foo(null);
+
+%PrepareFunctionForOptimization(wasm_caller);
+testCallStack();
+%OptimizeFunctionOnNextCall(wasm_caller);
+testCallStack();
+
+function testCallStack() {
+  try {
+    wasm_caller();
+    assertUnreachable();
+  } catch (e) {
+    assertMatches(
+`TypeError: type incompatibility when transforming from/to JS
+    at wasm_caller .*\\.js:14:44\\)
+    at testCallStack .*\\.js:23:5\\).*`,
+      e.stack,);
+  }
+}
