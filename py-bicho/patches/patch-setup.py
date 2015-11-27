$NetBSD$

--- setup.py.orig	2011-06-28 10:58:38.000000000 +0000
+++ setup.py
@@ -21,6 +21,9 @@
 #          Francisco Rivas <frivas@libresoft.es>
 #          Luis Cañas Díaz <lcanas@libresoft.es>
 #
+
+import sys 
+
 from distutils.core import setup
 
 setup(name = "Bicho",
@@ -30,5 +33,5 @@ setup(name = "Bicho",
       description = "Analysis tool for Issue/Bug Tracking Systems",
       url = "https://projects.libresoft.es/projects/bicho",      
       packages = ['Bicho', 'Bicho.backends', 'Bicho.db'],
-      data_files = [('share/man/man1/',['doc/bicho.1'])],
-      scripts = ["bin/bicho"])
+      data_files = [('man/man1/',['doc/bicho.1'])],
+      scripts = ["bin/bicho"+sys.version[0:3]])
