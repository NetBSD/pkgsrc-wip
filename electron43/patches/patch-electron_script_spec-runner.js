$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/script/spec-runner.js.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/script/spec-runner.js
@@ -584,7 +584,7 @@ function toVitestInvocation(exe, specDir
   };
   let command = process.execPath;
   let commandArgs = vitestArgs;
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
     // The mock D-Bus services are started once around the whole run; every
     // Electron worker inherits the bus addresses from the CLI's environment.
     commandArgs = [path.resolve(__dirname, 'dbus_mock.py'), command, ...commandArgs];
@@ -687,7 +687,7 @@ async function installSpecModules(dir) {
     process.exit(1);
   }
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
     const { status: rebuildStatus } = childProcess.spawnSync('npm', ['rebuild', 'abstract-socket'], {
       env,
       cwd: dir,
@@ -765,7 +765,7 @@ async function installSpecModules(dir) {
 // the same GCC that rejects the headers, so nothing on that host can build
 // the fixtures.
 function getNativeAddonToolchainEnv() {
-  if (args.electronVersion || process.platform !== 'linux') {
+  if (args.electronVersion || (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')) {
     return {};
   }
   const outDir = utils.getOutDir();
