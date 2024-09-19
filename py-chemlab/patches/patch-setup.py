$NetBSD$

Avoid downloading during the build.

--- setup.py.orig	2013-09-10 17:06:46.000000000 +0000
+++ setup.py
@@ -1,5 +1,5 @@
-from distribute_setup import use_setuptools
-use_setuptools()
+#from distribute_setup import use_setuptools
+#use_setuptools()
 from setuptools import setup, find_packages, Extension
 from Cython.Distutils import build_ext
 import numpy as np
