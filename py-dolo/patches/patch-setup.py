$NetBSD: patch-setup.py,v 1.2 2014/05/14 21:57:06 jihbed Exp $

--- setup.py.orig	2014-05-14 22:12:44.000000000 +0100
+++ setup.py	2014-05-14 22:17:16.000000000 +0100
@@ -1,3 +1,5 @@
+import sys
+
 from setuptools import setup, find_packages
 from distutils.extension import Extension
 
@@ -19,7 +21,7 @@
 
     include_dirs = [np.get_include()],
 
-    scripts = ['bin/dolo-recs', 'bin/dolo-matlab', 'bin/dolo-julia', 'bin/dolo'],
+    scripts = ['bin/dolo-recs'+sys.version[0:3], 'bin/dolo-matlab'+sys.version[0:3], 'bin/dolo-julia'+sys.version[0:3], 'bin/dolo'+sys.version[0:3]],
 
     install_requires = ["pyyaml","numba","numpy","cython"],
 
