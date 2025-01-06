$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-fs-write.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-fs-write.js
@@ -38,7 +38,7 @@ const constants = fs.constants;
 const { externalizeString, isOneByteString } = global;
 
 // Account for extra globals exposed by --expose_externalize_string.
-common.allowGlobals(externalizeString, isOneByteString, global.x);
+common.allowGlobals(createExternalizableString, externalizeString, isOneByteString, global.x);
 
 {
   const expected = 'ümlaut sechzig';  // Must be a unique string.
