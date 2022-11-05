$NetBSD$

--- setup.py.orig	2022-09-03 16:00:00.000000000 +0000
+++ setup.py
@@ -4,5 +4,5 @@ from setuptools import setup
 
 setup(
     setup_requires=['pbr'],
-    pbr=True,
-)
\ No newline at end of file
+    pbr=False,
+)
