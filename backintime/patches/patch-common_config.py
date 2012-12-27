$NetBSD: patch-common_config.py,v 1.1 2012/12/27 19:52:23 ryo-on Exp $

--- common/config.py.orig	2011-01-05 20:08:29.000000000 +0000
+++ common/config.py
@@ -29,7 +29,7 @@ import logger
 
 _=gettext.gettext
 
-gettext.bindtextdomain( 'backintime', '/usr/share/locale' )
+gettext.bindtextdomain( 'backintime', '@PREFIX@/share/locale' )
 gettext.textdomain( 'backintime' )
 
 
