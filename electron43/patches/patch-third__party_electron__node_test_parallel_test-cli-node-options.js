$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-cli-node-options.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-cli-node-options.js
@@ -72,7 +72,6 @@ if (common.hasCrypto) {
 expect('--abort_on-uncaught_exception', 'B\n');
 expect('--disallow-code-generation-from-strings', 'B\n');
 expect('--expose-gc', 'B\n');
-expect('--huge-max-old-generation-size', 'B\n');
 expect('--jitless', 'B\n');
 expect('--max-old-space-size=0', 'B\n');
 expect('--max-semi-space-size=0', 'B\n');
