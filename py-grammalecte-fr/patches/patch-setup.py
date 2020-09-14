$NetBSD$

--- setup.py.orig	2020-07-23 11:00:40.000000000 +0000
+++ setup.py
@@ -3,7 +3,7 @@ See:
 https://packaging.python.org/en/latest/distributing.html
 https://github.com/pypa/sampleproject
 """
-
+import sys
 # Always prefer setuptools over distutils
 from setuptools import setup, find_packages
 
@@ -62,7 +62,7 @@ setup(
     keywords='French grammar checker correcteur grammatical français',
 
     # Scripts
-    scripts=['grammalecte-cli.py', 'grammalecte-server.py'],
+    scripts=['grammalecte-cli.py'+sys.version[0:3], 'grammalecte-server.py'+sys.version[0:3]],
 
     # You can just specify the packages manually here if your project is
     # simple. Or you can use find_packages().
