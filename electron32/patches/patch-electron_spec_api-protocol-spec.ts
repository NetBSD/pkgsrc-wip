$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-protocol-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/api-protocol-spec.ts
@@ -1738,7 +1738,8 @@ describe('protocol module', () => {
 
     // TODO(nornagon): this test doesn't pass on Linux currently, investigate.
     // test is also flaky on CI on macOS so it is currently disabled there as well.
-    ifit(process.platform !== 'linux' && (!process.env.CI || process.platform !== 'darwin'))('is fast', async () => {
+    ifit((process.platform !== 'linux' && process.platform !== 'freebsd' &&
+           process.platform !== 'openbsd' && process.platform !== 'netbsd') && (!process.env.CI || process.platform !== 'darwin'))('is fast', async () => {
       // 128 MB of spaces.
       const chunk = new Uint8Array(128 * 1024 * 1024);
       chunk.fill(' '.charCodeAt(0));
