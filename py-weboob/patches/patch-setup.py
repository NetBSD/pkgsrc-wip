$NetBSD$

--- setup.py.orig	2014-10-17 12:10:14.000000000 +0000
+++ setup.py
@@ -111,7 +111,7 @@ def install_weboob():
         packages = packages - qt_packages
 
     data_files = [
-        ('share/man/man1', glob.glob('man/*')),
+        ('man/man1', glob.glob('man/*')),
     ]
     if options.xdg:
         data_files.extend([
@@ -185,7 +185,7 @@ def install_weboob():
 
 class Options(object):
     hildon = False
-    qt = False
+    qt = True
     xdg = True
     deps = True
 
