$NetBSD: patch-setup.py,v 1.1 2014/10/03 21:12:34 jihbed Exp $
--- setup.py.orig	2014-09-30 19:48:38.000000000 +0100
+++ setup.py	2014-10-03 22:01:18.000000000 +0100
@@ -1,3 +1,4 @@
+import sys
 from setuptools import setup
 
 
@@ -6,7 +7,7 @@
     version='0.1.3',
     author='Roman Kiselev',
     author_email='roman.kiselew@gmail.com',
-    scripts=['speview.py'],
+    scripts=['speview.py'+sys.version[0:3]],
     url='https://github.com/ximeg/speview',
     license='LICENSE.txt',
     description='Program to display binary SPE files with Raman spectra',
