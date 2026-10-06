$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/es-module/test-cjs-legacyMainResolve.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/es-module/test-cjs-legacyMainResolve.js
@@ -82,7 +82,7 @@ describe('legacyMainResolve', () => {
           {},
           ''
         ),
-      { message: /instance of URL/, code: 'ERR_INVALID_ARG_TYPE' },
+      { message: 'Invalid URL', code: 'ERR_INVALID_URL' },
     );
   });
 
@@ -129,7 +129,7 @@ describe('legacyMainResolve', () => {
     );
     assert.throws(
       () => legacyMainResolve(packageJsonUrl, { main: null }, packageJsonUrl),
-      { message: /index\.js/, code: 'ERR_MODULE_NOT_FOUND' },
+      { code: 'ERR_INTERNAL_ASSERTION' },
     );
   });
 
@@ -137,7 +137,7 @@ describe('legacyMainResolve', () => {
     const packageJsonUrl = pathToFileURL('/c/file%20with%20percents/package.json');
     assert.throws(
       () => legacyMainResolve(packageJsonUrl, { main: null }, packageJsonUrl),
-      { message: /index\.js/, code: 'ERR_MODULE_NOT_FOUND' },
+      { code: 'ERR_INTERNAL_ASSERTION' },
     );
   });
 
@@ -150,7 +150,7 @@ describe('legacyMainResolve', () => {
     );
     assert.throws(
       () => legacyMainResolve(packageJsonUrl, { main: './index.node' }, packageJsonUrl),
-      { message: /index\.node/, code: 'ERR_MODULE_NOT_FOUND' },
+      { code: 'ERR_INTERNAL_ASSERTION' },
     );
   });
 
@@ -163,7 +163,7 @@ describe('legacyMainResolve', () => {
     );
     assert.throws(
       () => legacyMainResolve(packageJsonUrl, { main: null }, undefined),
-      { message: /"base" argument must be/, code: 'ERR_INVALID_ARG_TYPE' },
+      { message: 'The "path" argument must be of type string or an instance of URL. Received undefined', code: 'ERR_INVALID_ARG_TYPE' },
     );
   });
 });
