$NetBSD$

Fix error "Unknown distribution option: 'install_requires'"

--- setup.py.orig	2015-08-11 08:32:25.000000000 +0000
+++ setup.py
@@ -1,4 +1,4 @@
-from distutils.core import setup
+from setuptools import setup
 setup(
     name = 'idalink',
     description = 'An interface to the insides of IDA!',
