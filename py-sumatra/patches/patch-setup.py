$NetBSD: patch-setup.py,v 1.1 2012/08/17 18:07:23 slitvinov Exp $

--- setup.py.orig	2011-03-14 13:34:29.000000000 +0000
+++ setup.py
@@ -6,6 +6,7 @@ from setuptools import setup
 from distutils.command.sdist import sdist
 from src.__init__ import __version__
 import os
+import sys
 
 
 class sdist_hg(sdist):
@@ -38,7 +39,7 @@ setup(
     package_data = {'sumatra': ['web/media/smt.css',
                                 'web/media/*.png',
                                 'web/templates/*.html']},
-    scripts = ['bin/smt', 'bin/smtweb'],
+    scripts= ['bin/smt'+sys.version[:3], 'bin/smtweb'+sys.version[:3]],
     author = "Andrew P. Davison",
     author_email = "andrewpdavison@gmail.com",
     description = "A tool for automated tracking of computation-based scientific projects",
