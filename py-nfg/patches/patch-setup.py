$NetBSD: patch-setup.py,v 1.1 2014/06/20 19:14:30 jihbed Exp $

--- setup.py.orig	2014-06-20 19:58:10.000000000 +0100
+++ setup.py	2014-06-20 19:58:48.000000000 +0100
@@ -1,3 +1,5 @@
+import sys
+
 from distutils.core import setup
 from setuptools import find_packages
 
@@ -7,7 +9,7 @@
     author='James Bono',
     author_email='jwbono@gmail.com',
     packages= find_packages(),
-    scripts=['bin/hideandseek.py', 'bin/stackelberg.py'],
+    scripts=['bin/hideandseek.py'+sys.version[:3], 'bin/stackelberg.py'+sys.version[:3]],
     url='http://pypi.python.org/pypi/PyNFG/',
     license='LICENSE.txt',
     description='A Python package for implementing and solving Network form games.',
