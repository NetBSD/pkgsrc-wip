$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-browser-window-ignore-mouse-events.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/api-browser-window-ignore-mouse-events.spec.ts
@@ -45,11 +45,11 @@ type Page = { webContents: Electron.WebC
 // Nothing can inject input into a Wayland compositor from a client, so only
 // X11 is covered on Linux.
 const hasRealInput =
-  process.platform === 'win32' || process.platform === 'darwin' || (process.platform === 'linux' && !isWayland);
+  process.platform === 'win32' || process.platform === 'darwin' || ((process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') && !isWayland);
 // { forward: true } is macOS and Windows only.
 const canForward = process.platform === 'win32' || process.platform === 'darwin';
 // Only these can ask the OS which window it hit tests at a point.
-const canHitTest = process.platform === 'win32' || process.platform === 'linux';
+const canHitTest = process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd';
 
 // #target turns orange while hovered. Element.matches(':hover') is not usable
 // here: it stays false while the (never focused) window is inactive even
