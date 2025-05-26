$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/fs/watchers.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/fs/watchers.js
@@ -292,12 +292,13 @@ function emitCloseNT(self) {
 }
 
 // Legacy alias on the C++ wrapper object. This is not public API, so we may
-// want to runtime-deprecate it at some point. There's no hurry, though.
-ObjectDefineProperty(FSEvent.prototype, 'owner', {
-  __proto__: null,
-  get() { return this[owner_symbol]; },
-  set(v) { return this[owner_symbol] = v; },
-});
+if (!'owner' in FSEvent.prototype) {
+  ObjectDefineProperty(FSEvent.prototype, 'owner', {
+ __proto__: null,
+    get() { return this[owner_symbol]; },
+    set(v) { return this[owner_symbol] = v; }
+  });
+}
 
 let kResistStopPropagation;
 
