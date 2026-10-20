$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/script/pgo/collect-profile.js.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/script/pgo/collect-profile.js
@@ -75,7 +75,7 @@ function log(...args) {
 // network workload coverage degrades but collection still succeeds.
 function installTrustedCA(caCertPath) {
   try {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
       const nssDb = path.join(os.homedir(), '.pki', 'nssdb');
       if (!fs.existsSync(nssDb)) {
         fs.mkdirSync(nssDb, { recursive: true });
