$NetBSD$

Fix error "Unknown distribution option: 'install_requires'"

--- setup.py.orig	2015-12-29 05:03:09.000000000 +0000
+++ setup.py
@@ -1,4 +1,4 @@
-from distutils.core import setup
+from setuptools import setup
 setup(name='cooldict',
       version='1.02',
       description='Some useful dict-like structures',
