$NetBSD: patch-setup.py,v 1.1 2015/02/16 22:06:44 jihbed Exp $

--- setup.py.orig	2015-01-13 21:03:50.000000000 +0000
+++ setup.py
@@ -36,7 +36,7 @@
 #
 ################################################################################
 
-
+import sys
 import distutils
 from distutils.core import setup
 
@@ -81,7 +81,7 @@ setup(name="Gato",
       download_url = 'http://sourceforge.net/projects/gato/files/',
       packages=['Gato'],
       package_dir={'Gato': ''},
-      scripts=['scripts/Gato', 'scripts/Gred'],
+      scripts=['scripts/Gato'+sys.version[0:3], 'scripts/Gred'+sys.version[0:3]],
       classifiers=['Development Status :: 5 - Production/Stable',
                    'Environment :: MacOS X',
                    'Environment :: Win32 (MS Windows)',
