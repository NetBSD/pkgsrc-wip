$NetBSD: patch-tools_install.py,v 1.5 2013/03/21 21:41:04 fhajny Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2013-03-21 01:15:04.000000000 +0000
+++ tools/install.py
@@ -129,7 +129,7 @@ def files(action):
   if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
-    action(['doc/node.1'], 'share/man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
