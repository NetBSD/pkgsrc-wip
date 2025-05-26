$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-v8-stats.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-v8-stats.js
@@ -48,6 +48,10 @@ const expectedHeapSpaces = [
   'read_only_space',
   'shared_large_object_space',
   'shared_space',
+  'shared_trusted_large_object_space',
+  'shared_trusted_space',
+  'trusted_large_object_space',
+  'trusted_space'
 ];
 const heapSpaceStatistics = v8.getHeapSpaceStatistics();
 const actualHeapSpaceNames = heapSpaceStatistics.map((s) => s.space_name);
