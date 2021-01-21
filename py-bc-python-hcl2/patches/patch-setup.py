$NetBSD$

--- setup.py.orig	2021-01-12 18:49:20.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 """setup.py controls the build, testing, and distribution of the egg"""
 import re
 import os.path
+import sys
 from setuptools import setup, find_packages
 
 VERSION_REGEX = re.compile(r"""
@@ -65,6 +66,6 @@ setup(
     install_requires=get_requirements(),
     test_suite='nose.collector',
     scripts=[
-        'bin/hcl2tojson',
+        'bin/hcl2tojson'+sys.version[0:3],
     ],
 )
