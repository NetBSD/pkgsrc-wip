$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/common/globals.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/common/globals.js
@@ -63,6 +63,7 @@ const intrinsics = new Set([
   'SharedArrayBuffer',
   'Atomics',
   'WebAssembly',
+  'Iterator',
 ]);
 
 if (global.gc) {
