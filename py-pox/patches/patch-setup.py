$NetBSD$

--- setup.py.orig	2020-06-15 12:24:24.000000000 +0000
+++ setup.py
@@ -263,7 +263,7 @@ if has_setuptools:
 # close 'setup' call
 setup_code += """    
       zip_safe=False,
-      scripts=['scripts/pox'])
+      scripts=['scripts/pox'+sys.version[0:3]])
 """
 
 # exec the 'setup' code
