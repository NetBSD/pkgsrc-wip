$NetBSD$

* Add Free- and NetBSD support

--- ts/util/os/osMain.node.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/util/os/osMain.node.ts
@@ -8,10 +8,13 @@ import { getOSFunctions } from './shared
 const { readFileSync } = fsExtra;
 
 function getLinuxName(): string | undefined {
-  if (os.platform() !== 'linux') {
+  if (os.platform() !== 'linux' && os.platform() !== 'freebsd' && os.platform() !== 'netbsd') {
     return undefined;
   }
 
+  if (os.platform() === 'netbsd') {
+    return `${os.type()} ${os.release()}`;
+  }
   const etcOsRelease = readFileSync('/etc/os-release', 'utf-8');
   const match = etcOsRelease.match(/^PRETTY_NAME=(.+?)$/m);
   if (!match) {
@@ -49,7 +52,7 @@ function isWaylandEnabled(): boolean {
 }
 
 function isLinuxUsingKDE(): boolean {
-  return os.platform() === 'linux' && process.env.XDG_CURRENT_DESKTOP === 'KDE';
+  return (os.platform() === 'linux' || os.platform() === 'freebsd' || os.platform() === 'netbsd') && process.env.XDG_CURRENT_DESKTOP === 'KDE';
 }
 
 const OS = {
