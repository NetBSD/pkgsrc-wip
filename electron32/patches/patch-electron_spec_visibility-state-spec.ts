$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/visibility-state-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/visibility-state-spec.ts
@@ -12,7 +12,8 @@ import { closeWindow } from './lib/windo
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+                   process.platform !== 'openbsd' && process.platform !== 'netbsd')('document.visibilityState', () => {
   let w: BaseWindow & {webContents: WebContents};
 
   afterEach(async () => {
