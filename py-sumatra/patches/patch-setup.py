$NetBSD: patch-setup.py,v 1.2 2012/11/16 11:13:17 slitvinov Exp $

--- setup.py.orig	2012-10-18 13:02:49.000000000 +0000
+++ setup.py
@@ -6,6 +6,7 @@ from setuptools import setup
 from distutils.command.sdist import sdist
 from src.__init__ import __version__
 import os
+import sys
 
 
 class sdist_hg(sdist):
@@ -39,7 +40,7 @@ setup(
                                 'web/media/img/*', 'web/media/css/*.css', 'web/media/extras/fontawesome/font/*',
                                 'web/media/extras/fontawesome/sass/*', 'web/media/extras/fontawesome/css/*.css',          
                                 'web/templates/*.html']},
-    scripts = ['bin/smt', 'bin/smtweb'],
+    scripts= ['bin/smt'+sys.version[:3], 'bin/smtweb'+sys.version[:3]],
     author = "Andrew P. Davison",
     author_email = "andrewpdavison@gmail.com",
     description = "A tool for automated tracking of computation-based scientific projects",
