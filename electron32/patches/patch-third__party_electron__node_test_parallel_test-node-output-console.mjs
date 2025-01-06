$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-node-output-console.mjs.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-node-output-console.mjs
@@ -31,6 +31,7 @@ describe('console output', { concurrency
     .transform(snapshot.replaceWindowsLineEndings, snapshot.replaceWindowsPaths, replaceStackTrace);
   for (const { name, transform, env } of tests) {
     it(name, async () => {
+      if (env) env.ELECTRON_RUN_AS_NODE = 1;
       await snapshot.spawnAndAssert(
         fixtures.path(name),
         transform ?? defaultTransform,
