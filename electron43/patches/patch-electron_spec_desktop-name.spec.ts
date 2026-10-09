$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/desktop-name.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/desktop-name.spec.ts
@@ -10,7 +10,7 @@ const { defaultDesktopName }: typeof imp
   '../lib/browser/desktop-name.ts'
 );
 
-ifdescribe(process.platform === 'linux')('defaultDesktopName', () => {
+ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('defaultDesktopName', () => {
   it("derives an appropriate .desktop name from the app's human readable name", () => {
     const fallback = `${path.basename(process.execPath)}.desktop`;
     const cases: Array<[string | undefined, string]> = [
