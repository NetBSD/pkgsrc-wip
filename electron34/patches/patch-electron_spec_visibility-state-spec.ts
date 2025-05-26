$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/visibility-state-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/visibility-state-spec.ts
@@ -11,7 +11,7 @@ import { closeAllWindows } from './lib/w
 
 // visibilityState specs pass on linux with a real window manager but on CI
 // the environment does not let these specs pass
-ifdescribe(process.platform !== 'linux')('document.visibilityState', () => {
+ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('document.visibilityState', () => {
   let w: BaseWindow & {webContents: WebContents};
 
   before(() => {
