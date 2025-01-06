$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/bootstrap/node.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/bootstrap/node.js
@@ -134,6 +134,10 @@ process.domain = null;
 }
 process._exiting = false;
 
+// NOTE: Electron deletes this references before user code runs so that
+// internalBinding is not leaked to user code.
+process.internalBinding = internalBinding;
+
 // process.config is serialized config.gypi
 const binding = internalBinding('builtins');
 
