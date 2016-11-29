$NetBSD$

--- ui/webui/resources/js/cr.js.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/webui/resources/js/cr.js
@@ -451,6 +451,11 @@ var cr = cr || function() {
     get doc() {
       return document;
     },
+    
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
 
     /** Whether we are using a Mac or not. */
     get isMac() {
