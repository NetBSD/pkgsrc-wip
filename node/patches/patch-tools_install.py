$NetBSD: patch-tools_install.py,v 1.1 2012/08/09 13:03:45 fhajny Exp $

Install man pages under the right directory.
--- tools/install.py.orig	2012-08-07 18:56:58.000000000 +0000
+++ tools/install.py
@@ -191,7 +191,7 @@ def files(action):
           'deps/uv/include/uv-private/uv-unix.h',
           'deps/uv/include/uv-private/uv-win.h'],
           'include/node/uv-private/')
-  action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], '@PKGMANDIR@/man1/')
   action(['out/Release/node'], 'bin/node')
 
   # install unconditionally, checking if the platform supports dtrace doesn't
