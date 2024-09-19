$NetBSD$

Honor PKG_SYSCONFDIR.
Set pkgsrc compliant directories for SQLite database.

--- admin/install/wizard.php.orig	2021-02-13 10:31:06.000000000 +0000
+++ admin/install/wizard.php
@@ -12,7 +12,7 @@ if (isset($_SERVER['DC_RC_PATH'])) {
 } elseif (isset($_SERVER['REDIRECT_DC_RC_PATH'])) {
     define('DC_RC_PATH', $_SERVER['REDIRECT_DC_RC_PATH']);
 } else {
-    define('DC_RC_PATH', dirname(__FILE__) . '/../../inc/config.php');
+    define('DC_RC_PATH', '@PKG_SYSCONFDIR@/config.php');
 }
 
 #  ClearBricks and DotClear classes auto-loader
@@ -63,7 +63,7 @@ if (!empty($_POST)) {
     {
         if ($DBDRIVER == 'sqlite') {
             if (strpos($DBNAME, '/') === false) {
-                $sqlite_db_directory = dirname(DC_RC_PATH) . '/../db/';
+                $sqlite_db_directory = '@DOTCLEAR_DBDIR@';
                 files::makeDir($sqlite_db_directory, true);
 
                 # Can we write sqlite_db_directory ?
@@ -99,7 +99,7 @@ if (!empty($_POST)) {
         }
 
         # Does config.php.in exist?
-        $config_in = dirname(__FILE__) . '/../../inc/config.php.in';
+        $config_in = '@PKG_SYSCONFDIR@/config.php.in';
         if (!is_file($config_in)) {
             throw new Exception(sprintf(__('File %s does not exist.'), $config_in));
         }
