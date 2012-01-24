$NetBSD: patch-index.php,v 1.1.1.1 2012/01/24 09:13:07 triaxx Exp $

Substitution for data directory.

--- index.php.orig	2012-01-11 21:17:28.000000000 +0000
+++ index.php
@@ -8,7 +8,7 @@
 // (but autocomplete fields will only work if you have php 5.2.x)
 // -----------------------------------------------------------------------------------------------
 // User config:
-$GLOBALS['config']['DATADIR'] = 'data'; // Data subdirectory
+$GLOBALS['config']['DATADIR'] = '@DATADIR@'; // Data subdirectory
 $GLOBALS['config']['CONFIG_FILE'] = $GLOBALS['config']['DATADIR'].'/config.php'; // Configuration file (user login/password)
 $GLOBALS['config']['DATASTORE'] = $GLOBALS['config']['DATADIR'].'/datastore.php'; // Data storage file.
 $GLOBALS['config']['LINKS_PER_PAGE'] = 20; // Default links per page.
@@ -18,7 +18,7 @@ $GLOBALS['config']['BAN_DURATION'] = 180
 $GLOBALS['config']['OPEN_SHAARLI'] = false; // If true, anyone can add/edit/delete links without having to login
 $GLOBALS['config']['HIDE_TIMESTAMPS'] = false; // If true, the moment when links were saved are not shown to users that are not logged in.
 $GLOBALS['config']['ENABLE_THUMBNAILS'] = true; // Enable thumbnails in links.
-$GLOBALS['config']['CACHEDIR'] = 'cache'; // Cache directory for thumbnails for SLOW services (like flickr)
+$GLOBALS['config']['CACHEDIR'] = '@CACHEDIR@'; // Cache directory for thumbnails for SLOW services (like flickr)
 $GLOBALS['config']['ENABLE_LOCALCACHE'] = true; // Enable Shaarli to store thumbnail in a local cache. Disable to reduce webspace usage.
 $GLOBALS['config']['PUBSUBHUB_URL'] = ''; // PubSubHubbub support. Put an empty string to disable, or put your hub url here to enable.
                                           // Note: You must have publisher.php in the same directory as Shaarli index.php
@@ -38,7 +38,7 @@ error_reporting(E_ALL^E_WARNING);  // Se
 
 include "inc/rain.tpl.class.php"; //include Rain TPL
 raintpl::$tpl_dir = "tpl/"; // template directory
-raintpl::$cache_dir = "tmp/"; // cache directory
+raintpl::$cache_dir = "@CACHEDIR@"; // cache directory
 
 ob_start();
 
