$NetBSD: patch-setup.py,v 1.1 2014/03/30 20:49:14 krytarowski Exp $
Use the right path for man-pages in pkgsrc.

--- setup.py.orig	2014-03-29 19:45:44.000000000 +0000
+++ setup.py
@@ -150,10 +150,7 @@ class InstallData(install_data):
     return data_files
 
 
-if platform.system() in ['FreeBSD', 'OpenBSD']:
-  man_dir = 'man'
-else:
-  man_dir = 'share/man'
+man_dir = 'man'
 
 setup(name=APP_NAME.capitalize(),
       version=APP_VERSION,
