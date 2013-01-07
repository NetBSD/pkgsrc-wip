$NetBSD: patch-tools_install.py,v 1.2 2013/01/07 14:58:40 fhajny Exp $

Install man pages under the right directory.
--- tools/install.py.orig	2012-12-12 22:44:54.000000000 +0000
+++ tools/install.py
@@ -201,7 +201,7 @@ def files(action):
   if 'freebsd' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
-    action(['doc/node.1'], 'share/man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
 
   if 'true' == variables.get('node_install_waf'): waf_files(action)
   if 'true' == variables.get('node_install_npm'): npm_files(action)
