$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/script/spec-runner.js.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/script/spec-runner.js
@@ -200,7 +200,7 @@ async function runTestUsingElectron (spe
     exe = path.resolve(BASE, utils.getElectronExec());
   }
   const runnerArgs = [`electron/${specDir}`, ...unknownArgs.slice(2)];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
     runnerArgs.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe);
     exe = 'python3';
   }
