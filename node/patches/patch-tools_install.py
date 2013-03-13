$NetBSD: patch-tools_install.py,v 1.4 2013/03/13 13:06:33 fhajny Exp $

Install man pages under the right directory.

--- tools/install.py.orig	2013-03-11 00:36:28.000000000 +0000
+++ tools/install.py
@@ -119,7 +119,7 @@ def npm_files(action):
     assert(0) # unhandled action type
 
 def files(action):
-  action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], '@PKGMANDIR@/man1/')
   action(['out/Release/node'], 'bin/node')
 
   # install unconditionally, checking if the platform supports dtrace doesn't
@@ -130,7 +130,7 @@ def files(action):
   if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
-    action(['doc/node.1'], 'share/man/man1/')
+    action(['doc/node.1'], '@PKGMANDIR@/man1/')
 
   if 'true' == variables.get('node_install_npm'): npm_files(action)
 
