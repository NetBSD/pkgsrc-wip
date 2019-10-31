$NetBSD$

Relax the dependency on Unicode

--- setup.py.orig	2015-06-05 06:29:19.000000000 +0000
+++ setup.py
@@ -16,7 +16,7 @@ setup(
     packages=find_packages(),
     install_requires=[
         'regex',
-        'Unidecode>=0.04.14,<0.05',
+        'Unidecode>=0.04.14',
     ],
 
     license='GNU GPLv3',
