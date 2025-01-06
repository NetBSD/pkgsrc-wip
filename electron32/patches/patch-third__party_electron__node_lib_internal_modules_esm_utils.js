$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/esm/utils.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/esm/utils.js
@@ -30,7 +30,7 @@ const {
   ERR_VM_DYNAMIC_IMPORT_CALLBACK_MISSING,
   ERR_INVALID_ARG_VALUE,
 } = require('internal/errors').codes;
-const { getOptionValue } = require('internal/options');
+const { getOptionValue, getEmbedderOptions } = require('internal/options');
 const {
   loadPreloadModules,
   initializeFrozenIntrinsics,
@@ -273,12 +273,13 @@ let _forceDefaultLoader = false;
  * @param {boolean} [forceDefaultLoader=false] - A boolean indicating disabling custom loaders.
  */
 function initializeESM(forceDefaultLoader = false) {
+  const shouldSetOnIsolate = !getEmbedderOptions().shouldNotRegisterESMLoader;
   _forceDefaultLoader = forceDefaultLoader;
   initializeDefaultConditions();
   // Setup per-realm callbacks that locate data or callbacks that we keep
   // track of for different ESM modules.
-  setInitializeImportMetaObjectCallback(initializeImportMetaObject);
-  setImportModuleDynamicallyCallback(importModuleDynamicallyCallback);
+  setInitializeImportMetaObjectCallback(initializeImportMetaObject, shouldSetOnIsolate);
+  setImportModuleDynamicallyCallback(importModuleDynamicallyCallback, shouldSetOnIsolate);
 }
 
 /**
