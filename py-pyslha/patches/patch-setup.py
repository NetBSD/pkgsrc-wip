$NetBSD$

--- setup.py.orig	2021-01-11 13:36:04.000000000 +0000
+++ setup.py
@@ -1,5 +1,6 @@
 #! /usr/bin/env python
 
+import sys
 from distutils.core import setup
 
 ## Setup definition
@@ -9,7 +10,7 @@ __doc__ = pyslha.__doc__
 setup(name = 'pyslha',
       version = pyslha.__version__,
       py_modules = ["pyslha"],
-      scripts = ["slhaplot", "slha2isawig", "isawig2slha"],
+      scripts = ["slhaplot"+sys.version[0:3], "slha2isawig"+sys.version[0:3], "isawig2slha"+sys.version[0:3]],
       install_requires = ["tex2pix >=0.1.5"],
       author = 'Andy Buckley',
       author_email = 'andy@insectnation.org',
