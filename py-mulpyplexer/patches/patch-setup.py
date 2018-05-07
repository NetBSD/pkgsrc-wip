$NetBSD$

Fix error "Unknown distribution option: 'install_requires'"

--- setup.py.orig	2017-08-10 02:47:00.000000000 +0000
+++ setup.py
@@ -1,5 +1,5 @@
 import os
-from distutils.core import setup
+from setuptools import setup
 
 setup(
     name='mulpyplexer',
