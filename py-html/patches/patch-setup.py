$NetBSD$

Use setuptools.
str.decode() has been removed in Python 3.

--- setup.py.orig	2011-06-24 01:02:39.000000000 +0000
+++ setup.py
@@ -1,6 +1,9 @@
 #! /usr/bin/env python
 
-from distutils.core import setup
+try:
+    from setuptools import setup
+except ImportError:
+    from distutils.core import setup
 
 from html import __version__, __doc__
 
@@ -9,7 +12,7 @@ setup(
     name = "html",
     version = __version__,
     description = "simple, elegant HTML, XHTML and XML generation",
-    long_description = __doc__.decode('utf8'),
+    long_description = __doc__,
     author = "Richard Jones",
     author_email = "rjones@ekit-inc.com",
     py_modules = ['html'],
