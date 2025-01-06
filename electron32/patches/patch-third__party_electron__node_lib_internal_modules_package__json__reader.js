$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/package_json_reader.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/package_json_reader.js
@@ -12,7 +12,7 @@ const {
 const {
   ERR_INVALID_PACKAGE_CONFIG,
 } = require('internal/errors').codes;
-const { internalModuleReadJSON } = internalBinding('fs');
+const internalFsBinding = internalBinding('fs');
 const { resolve, sep, toNamespacedPath } = require('path');
 const permission = require('internal/process/permission');
 const { kEmptyObject } = require('internal/util');
@@ -53,7 +53,7 @@ function read(jsonPath, { base, specifie
   const {
     0: string,
     1: containsKeys,
-  } = internalModuleReadJSON(
+  } = internalFsBinding.internalModuleReadJSON(
     toNamespacedPath(jsonPath),
   );
   const result = {
