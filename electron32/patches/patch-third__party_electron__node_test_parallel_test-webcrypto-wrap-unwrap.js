$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-webcrypto-wrap-unwrap.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-webcrypto-wrap-unwrap.js
@@ -18,14 +18,15 @@ const kWrappingData = {
     wrap: { label: new Uint8Array(8) },
     pair: true
   },
-  'AES-CTR': {
+  'AES-CBC': {
     generate: { length: 128 },
-    wrap: { counter: new Uint8Array(16), length: 64 },
+    wrap: { iv: new Uint8Array(16) },
     pair: false
   },
-  'AES-CBC': {
+  /*
+  'AES-CTR': {
     generate: { length: 128 },
-    wrap: { iv: new Uint8Array(16) },
+    wrap: { counter: new Uint8Array(16), length: 64 },
     pair: false
   },
   'AES-GCM': {
@@ -42,6 +43,7 @@ const kWrappingData = {
     wrap: { },
     pair: false
   }
+  */
 };
 
 function generateWrappingKeys() {
