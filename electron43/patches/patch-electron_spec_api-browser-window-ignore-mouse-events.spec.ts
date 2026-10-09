$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-browser-window-ignore-mouse-events.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-browser-window-ignore-mouse-events.spec.ts
@@ -41,11 +41,11 @@ type PageEvent = { type: string; x?: num
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
