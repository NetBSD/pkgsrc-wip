$NetBSD$

Change configuration file path from current directory to pkgsrc-compliant path.

--- carddav_common.php.orig	2018-10-01 07:23:22.000000000 +0000
+++ carddav_common.php
@@ -373,7 +373,7 @@ class carddav_common
 
 	$rcmail = rcmail::get_instance();
 	$prefs = array();
-	$configfile = dirname(__FILE__)."/config.inc.php";
+	$configfile = "@PKG_SYSCONFDIR@/config.inc.php";
 	if (file_exists($configfile)){
 		require("$configfile");
 	}
