$NetBSD: patch-setup.py,v 1.1 2014/05/02 09:00:34 ahp-nils Exp $

setup.py does build but does not install without
this patch.

--- setup.py.orig	2014-04-30 13:42:23.000000000 +0000
+++ setup.py
@@ -1,5 +1,8 @@
 import os
-from distutils.core import setup
+try:
+    from setuptools import setup
+except ImportError:
+    from distutils.core import setup
 import pyqueue
 
 # setup.py actually relies on py_module
