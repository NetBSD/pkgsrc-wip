$NetBSD: patch-setup.py,v 1.1 2012/09/10 22:11:35 jihbed Exp $

--- setup.py.orig	2012-09-10 22:28:50.000000000 +0100
+++ setup.py	2012-09-10 22:32:45.000000000 +0100
@@ -1,4 +1,5 @@
 from setuptools import setup, find_packages
+import sys
 
 __version__ = "0.4-dev"
 
@@ -7,7 +8,7 @@
     version = __version__,
     packages = find_packages('src'),
     package_dir = {'':'src'},
-    scripts = ['src/bin/dolo-recs.py', 'src/bin/dolo-matlab.py'],
+    scripts = ['src/bin/dolo-recs.py'+sys.version[0:3], 'src/bin/dolo-matlab.py'+sys.version[0:3]],
     install_requires = ["pyyaml","sympy","numpy","matplotlib"],
     author = "Pablo Winant",
     author_email = "pablo.winant@gmail.com",
