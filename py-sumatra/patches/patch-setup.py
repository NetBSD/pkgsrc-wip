$NetBSD: patch-setup.py,v 1.4 2013/05/28 18:27:24 slitvinov Exp $

--- setup.py.orig	2013-02-22 13:20:01.000000000 +0000
+++ setup.py
@@ -6,6 +6,7 @@ from setuptools import setup
 from distutils.command.sdist import sdist
 from src.__init__ import __version__
 import os
+import sys
 
 
 class sdist_hg(sdist):
@@ -42,7 +43,7 @@ setup(
                                 'web/media/extras/fontawesome/sass/*', 'web/media/extras/fontawesome/css/*.css',          
                                 'web/templates/*.html',
                                 'publishing/latex/sumatra.sty']},
-    scripts = ['bin/smt', 'bin/smtweb'],
+    scripts= ['bin/smt'+sys.version[:3], 'bin/smtweb'+sys.version[:3]],
     author = "Andrew P. Davison",
     author_email = "andrewpdavison@gmail.com",
     description = "A tool for automated tracking of computation-based scientific projects",
