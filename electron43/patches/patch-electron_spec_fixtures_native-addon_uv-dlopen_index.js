$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/fixtures/native-addon/uv-dlopen/index.js.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/fixtures/native-addon/uv-dlopen/index.js
@@ -4,7 +4,7 @@ const testLoadLibrary = require('./build
 
 const lib = (() => {
   switch (process.platform) {
-    case 'linux':
+    case 'linux': case 'freebsd': case 'netbsd':
       return path.resolve(__dirname, 'build/Release/foo.so');
     case 'darwin':
       return path.resolve(__dirname, 'build/Release/foo.dylib');
