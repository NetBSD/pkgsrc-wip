$NetBSD$

--- ui/webui/resources/js/cr.js.orig	2016-06-24 01:02:54.000000000 +0000
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
