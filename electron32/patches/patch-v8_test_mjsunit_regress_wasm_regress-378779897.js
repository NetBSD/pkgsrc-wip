$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/test/mjsunit/regress/wasm/regress-378779897.js.orig	2025-03-03 17:47:27.837842974 +0000
+++ v8/test/mjsunit/regress/wasm/regress-378779897.js
@@ -0,0 +1,22 @@
+// Copyright 2024 the V8 project authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+d8.file.execute("test/mjsunit/wasm/wasm-module-builder.js");
+
+const builder = new WasmModuleBuilder();
+builder.addMemory(49149);
+
+builder.addFunction('main', kSig_i_v).addBody([
+  ...wasmI32Const(-1118406780),
+  ...wasmI32Const(-1),
+  kAtomicPrefix, kExprI32AtomicOr8U, 0, 0
+]).exportFunc();
+
+let instance;
+try {
+  instance = builder.instantiate();
+} catch (e) {
+  assertException(e, RangeError, /Out of memory/);
+}
+if (instance) instance.exports.main();
