$NetBSD: patch-tools_install.py,v 1.3 2013/01/23 14:53:48 fhajny Exp $

Install man pages under the right directory.
--- tools/install.py.orig	2013-01-18 20:15:41.000000000 +0000
+++ tools/install.py	2013-01-23 13:57:39.128772373 +0000
@@ -206,7 +206,7 @@
   if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
-    action(['doc/node.1'], 'share/man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
 
   if 'true' == variables.get('node_install_waf'): waf_files(action)
   if 'true' == variables.get('node_install_npm'): npm_files(action)
