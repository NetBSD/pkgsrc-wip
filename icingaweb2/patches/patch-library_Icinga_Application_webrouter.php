$NetBSD: $

Replace convoluted path computation by something much simpler that 
actually works reliably.

--- library/Icinga/Application/webrouter.php.orig	2025-11-18 18:00:39.000000000 +0100
+++ library/Icinga/Application/webrouter.php	2026-11-16 17:21:15.305836998 +0100
@@ -10,12 +10,6 @@
 
 error_reporting(E_ALL & ~E_DEPRECATED & ~E_USER_DEPRECATED);
 
-if (isset($_SERVER['REQUEST_URI'])) {
-    $ruri = $_SERVER['REQUEST_URI'];
-} else {
-    return false;
-}
-
 // Workaround, PHPs internal Webserver seems to mess up SCRIPT_FILENAME
 // as it prefixes it's absolute path with DOCUMENT_ROOT
 if (preg_match('/^PHP.*Development Server/', $_SERVER['SERVER_SOFTWARE'])) {
@@ -29,18 +23,12 @@
 $baseDir = $_SERVER['DOCUMENT_ROOT'];
 $baseDir = dirname($_SERVER['SCRIPT_FILENAME']);
 
-// Fix aliases
-$remove = str_replace('\\', '/', dirname($_SERVER['PHP_SELF']));
-if (substr($ruri, 0, strlen($remove)) !== $remove) {
-    return false;
-}
-$ruri = ltrim(substr($ruri, strlen($remove)), '/');
-
-if (strpos($ruri, '?') === false) {
-    $params = '';
-    $path = $ruri;
+if (!isset($_SERVER['PATH_INFO'])) {
+    $path = '';
+} elseif ($_SERVER['PATH_INFO'] === '') {
+    $path = '';
 } else {
-    list($path, $params) = preg_split('/\?/', $ruri, 2);
+    $path = ltrim($_SERVER['PATH_INFO'], '/'); // remove leading slash
 }
 
 $special = array(
