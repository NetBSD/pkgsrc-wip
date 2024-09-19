$NetBSD: patch-conf_dokuwiki.php,v 1.1 2012/12/21 04:25:34 triaxx Exp $

Substitution for data directory.

--- conf/dokuwiki.php.orig	2012-10-13 11:25:31.000000000 +0000
+++ conf/dokuwiki.php
@@ -20,7 +20,7 @@ $conf['template']    = 'dokuwiki';      
 $conf['tagline']     = '';                //tagline in header (if template supports it)
 $conf['sidebar']     = 'sidebar';         //name of sidebar in root namespace (if template supports it)
 $conf['license']     = 'cc-by-nc-sa';     //see conf/license.php
-$conf['savedir']     = './data';          //where to store all the files
+$conf['savedir']     = '@DATADIR@';          //where to store all the files
 $conf['basedir']     = '';                //absolute dir from serveroot - blank for autodetection
 $conf['baseurl']     = '';                //URL to server including protocol - blank for autodetect
 $conf['cookiedir']   = '';                //path to use in cookies - blank for basedir
