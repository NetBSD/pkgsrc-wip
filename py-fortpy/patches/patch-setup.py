$NetBSD: patch-setup.py,v 1.1 2014/08/06 21:34:53 jihbed Exp $

--- setup.py.orig	2014-08-06 22:12:56.000000000 +0100
+++ setup.py	2014-08-06 22:22:21.000000000 +0100
@@ -1,4 +1,7 @@
 #!/usr/bin/env python
+
+import sys
+
 try:
     from setuptools import setup
     args = {}
@@ -34,7 +37,7 @@
       packages=['fortpy', 'fortpy.parsers', 'fortpy.isense', 'fortpy.testing',
                 'fortpy.templates', 'fortpy.interop',
                 'fortpy.printing' ],
-      scripts=['fortpy/scripts/compare.py', 'fortpy/scripts/convert.py', 'fortpy/scripts/runtests.py'],
+      scripts=['fortpy/scripts/compare.py'+sys.version[0:3], 'fortpy/scripts/convert.py'+sys.version[0:3], 'fortpy/scripts/runtests.py'+sys.version[0:3]],
       package_data={'fortpy': ['isense/builtin.xml']},
       include_package_data=True,
       classifiers=[
