$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-shell.spec.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/api-shell.spec.ts
@@ -37,7 +37,7 @@ describe('shell module', () => {
 
     afterEach(async () => {
       // reset env vars to prevent side effects
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
         process.env.DE = envVars.de;
         process.env.BROWSER = envVars.browser;
         process.env.DISPLAY = envVars.display;
@@ -57,6 +57,16 @@ describe('shell module', () => {
         process.env.DE = 'generic';
         process.env.DISPLAY = '';
         requestReceived = Promise.resolve();
+      } else if (process.platform === 'freebsd') {
+        process.env.BROWSER = '/usr/bin/true';
+        process.env.DE = 'generic';
+        process.env.DISPLAY = '';
+        requestReceived = Promise.resolve();
+      } else if (process.platform === netbsd') {
+        process.env.BROWSER = '/usr/bin/true';
+        process.env.DE = 'generic';
+        process.env.DISPLAY = '';
+        requestReceived = Promise.resolve();
       } else if (process.platform === 'darwin') {
         // On the Mac CI machines, Safari tries to ask for a password to the
         // code signing keychain we set up to test code signing (see
