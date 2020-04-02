$NetBSD$

Get the config out of the share directory.

--- admin/install/index.php.orig	2016-03-27 09:27:58.000000000 +0000
+++ admin/install/index.php
@@ -15,7 +15,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
 	$rc_path = $_SERVER['REDIRECT_DC_RC_PATH'];
 } else {
-	$rc_path = dirname(__FILE__).'/../../inc/config.php';
+	$rc_path = '@DC_WWW@/config.php';
 }
 
 require dirname(__FILE__).'/../../inc/prepend.php';
