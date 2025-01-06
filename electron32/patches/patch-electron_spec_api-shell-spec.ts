$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-shell-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/api-shell-spec.ts
@@ -26,7 +26,8 @@ describe('shell module', () => {
 
     afterEach(async () => {
       // reset env vars to prevent side effects
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' ||
+           process.platform === 'openbsd' || process.platform === 'netbsd') {
         process.env.DE = envVars.de;
         process.env.BROWSER = envVars.browser;
         process.env.DISPLAY = envVars.display;
@@ -42,6 +43,11 @@ describe('shell module', () => {
         process.env.DE = 'generic';
         process.env.DISPLAY = '';
         requestReceived = Promise.resolve();
+      } else if (process.platform === 'freebsd' || process.platform === 'openbsd' || process.platform === 'netbsd') {
+        process.env.BROWSER = '/usr/bin/true';
+        process.env.DE = 'generic';
+        process.env.DISPLAY = '';
+        requestReceived = Promise.resolve();
       } else if (process.platform === 'darwin') {
         // On the Mac CI machines, Safari tries to ask for a password to the
         // code signing keychain we set up to test code signing (see
