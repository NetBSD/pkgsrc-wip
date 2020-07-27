$NetBSD$

--- ui/webui/resources/js/cr.js.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/webui/resources/js/cr.js
@@ -431,6 +431,11 @@ var cr = cr || function(global) {
       return /Mac/.test(navigator.platform);
     },
 
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.platform);
+    },
+
     /** Whether this is on the Windows platform or not. */
     get isWindows() {
       return /Win/.test(navigator.platform);
