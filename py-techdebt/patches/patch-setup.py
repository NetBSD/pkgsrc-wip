$NetBSD$

--- setup.py.orig	2020-08-11 21:28:57.000000000 +0000
+++ setup.py
@@ -1,4 +1,5 @@
 import setuptools
+import sys
 
 with open("README.md", "r") as fh:
 
@@ -8,7 +9,7 @@ setuptools.setup(
 
      name='techdebt',
      version='0.1.1',
-     scripts=['techdebt'] ,
+     scripts=['techdebt'+sys.version[0:3]] ,
      author="Laurent Cetinsoy",
      author_email="laurent.cetinsoy@gmail.com",
      description="A technical debt tracker package",
