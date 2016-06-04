$NetBSD$

Change location of public directory to /var.

--- inc/core/class.dc.core.php.orig	2016-03-27 09:27:59.000000000 +0000
+++ inc/core/class.dc.core.php
@@ -1414,7 +1414,7 @@ class dcCore
 				'Number of comments on feeds'),
 				array('post_url_format','string','{y}/{m}/{d}/{t}',
 				'Post URL format. {y}: year, {m}: month, {d}: day, {id}: post id, {t}: entry title'),
-				array('public_path','string','public',
+				array('public_path','string','@DC_WWW@/public',
 				'Path to public directory, begins with a / for a full system path'),
 				array('public_url','string','/public',
 				'URL to public directory'),
