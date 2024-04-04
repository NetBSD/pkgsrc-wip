$NetBSD$
upstream hasn't released a version without versioneer...
--- setup.py.orig	2024-04-04 14:22:31.725709049 +0000
+++ setup.py
@@ -2,11 +2,9 @@

 from os.path import exists
 from setuptools import setup
-import versioneer

 setup(name='partd',
-      version=versioneer.get_version(),
-      cmdclass=versioneer.get_cmdclass(),
+      version='1.4.1',
       description='Appendable key-value storage',
       url='http://github.com/dask/partd/',
       maintainer='Matthew Rocklin',
