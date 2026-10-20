$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/lib/spec-helpers.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/lib/spec-helpers.ts
@@ -19,7 +19,7 @@ export const ifit = (condition: boolean)
 export const ifdescribe = (condition: boolean) => (condition ? describe : describe.skip);
 
 export const isWayland =
-  process.platform === 'linux' &&
+  (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') &&
   (process.env.XDG_SESSION_TYPE === 'wayland' ||
     !!process.env.WAYLAND_DISPLAY ||
     process.argv.includes('--ozone-platform=wayland'));
