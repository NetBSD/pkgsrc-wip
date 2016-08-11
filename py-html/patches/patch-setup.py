$NetBSD$

Fix setup 

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
 
