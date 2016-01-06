$NetBSD$

--- admin/wizards/php.py.orig	2014-12-10 12:35:45.000000000 +0000
+++ admin/wizards/php.py
@@ -88,7 +88,8 @@ STD_ETC_PATHS = ['/etc/php.ini',
                  '/opt/local/etc/php*/php.ini',
                  '/etc/php*/*/php.ini',
                  '/etc/php*/php.ini',
-                 '/usr/local/lib*/php.ini']
+                 '/usr/local/lib*/php.ini',
+                 '@PKG_SYSCONFDIR@/php.ini']
 
 CFG_PREFIX    = 'tmp!wizard!php'
 
