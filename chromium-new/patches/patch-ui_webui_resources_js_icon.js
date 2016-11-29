$NetBSD$

--- ui/webui/resources/js/icon.js.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/webui/resources/js/icon.js
@@ -9,7 +9,7 @@ cr.define('cr.icon', function() {
    */
   function getSupportedScaleFactors() {
     var supportedScaleFactors = [];
-    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux) {
+    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux || cr.isBSD) {
       // All desktop platforms support zooming which also updates the
       // renderer's device scale factors (a.k.a devicePixelRatio), and
       // these platforms has high DPI assets for 2.0x. Use 1x and 2x in
