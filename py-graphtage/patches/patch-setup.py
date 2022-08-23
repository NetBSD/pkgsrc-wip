$NetBSD$

Lessen restrictions.

--- setup.py.orig	2022-05-16 18:47:54.000000000 +0000
+++ setup.py
@@ -38,7 +38,7 @@ setup(
     install_requires=[
         'colorama',
         'intervaltree',
-        'json5==0.9.5',
+        'json5>=0.9.5',
         'numpy>=1.19.4',
         'PyYAML',
         'scipy>=1.4.0',
