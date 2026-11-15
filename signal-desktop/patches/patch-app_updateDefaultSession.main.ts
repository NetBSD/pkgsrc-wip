$NetBSD$

* Add Free- and NetBSD support

--- app/updateDefaultSession.main.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ app/updateDefaultSession.main.ts
@@ -59,7 +59,7 @@ export function updateDefaultSession(
 
         // Wayland already shows a window/screen selection modal so we just
         // have to go with the source that we were given.
-        if (OS.isLinux() && OS.isWaylandEnabled() && sources.length === 1) {
+        if ((OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) && OS.isWaylandEnabled() && sources.length === 1) {
           callback({ video: sources[0] });
           return;
         }
