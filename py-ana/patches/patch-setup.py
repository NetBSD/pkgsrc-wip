$NetBSD$

Fix error "Unknown distribution option: 'install_requires'"

--- setup.py.orig	2018-03-27 23:17:53.000000000 +0000
+++ setup.py
@@ -1,2 +1,2 @@
-from distutils.core import setup
+from setuptools import setup
 setup(name='ana', version='0.05', install_requires=['future'], packages=['ana'])
