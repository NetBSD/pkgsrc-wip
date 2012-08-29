$NetBSD: patch-index.php,v 1.2 2012/08/29 13:32:34 triaxx Exp $

Substitution for data directory.

--- index.php.orig	2012-08-24 10:42:10.000000000 +0000
+++ index.php
@@ -6,7 +6,7 @@
 // Requires: php 5.1.x  (but autocomplete fields will only work if you have php 5.2.x)
 // -----------------------------------------------------------------------------------------------
 // Hardcoded parameter (These parameters can be overwritten by creating the file /config/options.php)
-$GLOBALS['config']['DATADIR'] = 'data'; // Data subdirectory
+$GLOBALS['config']['DATADIR'] = '@DATADIR@'; // Data subdirectory
 $GLOBALS['config']['CONFIG_FILE'] = $GLOBALS['config']['DATADIR'].'/config.php'; // Configuration file (user login/password)
 $GLOBALS['config']['DATASTORE'] = $GLOBALS['config']['DATADIR'].'/datastore.php'; // Data storage file.
 $GLOBALS['config']['LINKS_PER_PAGE'] = 20; // Default links per page.
@@ -16,7 +16,7 @@ $GLOBALS['config']['BAN_DURATION'] = 180
 $GLOBALS['config']['OPEN_SHAARLI'] = false; // If true, anyone can add/edit/delete links without having to login
 $GLOBALS['config']['HIDE_TIMESTAMPS'] = false; // If true, the moment when links were saved are not shown to users that are not logged in.
 $GLOBALS['config']['ENABLE_THUMBNAILS'] = true; // Enable thumbnails in links.
-$GLOBALS['config']['CACHEDIR'] = 'cache'; // Cache directory for thumbnails for SLOW services (like flickr)
+$GLOBALS['config']['CACHEDIR'] = '@CACHEDIR@'; // Cache directory for thumbnails for SLOW services (like flickr)
 $GLOBALS['config']['PAGECACHE'] = 'pagecache'; // Page cache directory.
 $GLOBALS['config']['ENABLE_LOCALCACHE'] = true; // Enable Shaarli to store thumbnail in a local cache. Disable to reduce webspace usage.
 $GLOBALS['config']['PUBSUBHUB_URL'] = ''; // PubSubHubbub support. Put an empty string to disable, or put your hub url here to enable.
@@ -48,7 +48,7 @@ error_reporting(E_ALL^E_WARNING);  // Se
 include "inc/rain.tpl.class.php"; //include Rain TPL
 raintpl::$tpl_dir = "tpl/"; // template directory
 if (!is_dir('tmp')) { mkdir('tmp',0705); chmod('tmp',0705); }
-raintpl::$cache_dir = "tmp/"; // cache directory
+raintpl::$cache_dir = "@CACHEDIR@"; // cache directory
 
 ob_start();  // Output buffering for the page cache.
 
@@ -2318,4 +2318,4 @@ if (isset($_SERVER["QUERY_STRING"]) && s
 if (isset($_SERVER["QUERY_STRING"]) && startswith($_SERVER["QUERY_STRING"],'ws=')) { processWS(); exit; } // Webservices (for jQuery/jQueryUI)
 if (!isset($_SESSION['LINKS_PER_PAGE'])) $_SESSION['LINKS_PER_PAGE']=$GLOBALS['config']['LINKS_PER_PAGE'];
 renderPage();
-?>
\ No newline at end of file
+?>
