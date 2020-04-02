$NetBSD$

Get the config out of the share directory.

--- inc/prepend.php.orig	2016-03-27 09:29:11.000000000 +0000
+++ inc/prepend.php
@@ -110,7 +110,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
 	define('DC_RC_PATH',$_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-	define('DC_RC_PATH',dirname(__FILE__).'/config.php');
+	define('DC_RC_PATH','@DC_WWW@/config.php');
 }
 
 if (!is_file(DC_RC_PATH))
