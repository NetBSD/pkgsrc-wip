$NetBSD: patch-setup.py,v 1.1.1.1 2011/12/29 21:58:32 jihbed Exp $

--- setup.py.orig	2009-10-01 15:51:06.000000000 +0100
+++ setup.py	2011-12-15 15:06:50.000000000 +0100
@@ -1,6 +1,7 @@
 #! /usr/bin/env python
 
 ## Get setuptools
+import sys
 import ez_setup
 ez_setup.use_setuptools()
 from setuptools import setup
@@ -20,7 +21,7 @@
       packages = ['pyfeyn'],
       include_package_data = True,
       install_requires = ['PyX >= 0.9'],
-      scripts = ['mkfeyndiag'],
+      scripts = ['mkfeyndiag'+sys.version[0:3]],
       author = ['Andy Buckley', 'Georg von Hippel'],
       author_email = 'pyfeyn@projects.hepforge.org',
       url = 'http://projects.hepforge.org/pyfeyn/',
