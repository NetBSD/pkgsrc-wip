$NetBSD: patch-setup.py,v 1.1 2020/09/16 10:40:15 jihbed Exp $
$

--- setup.py.orig	2020-06-15 12:47:22.000000000 +0000
+++ setup.py
@@ -299,7 +299,7 @@ if has_setuptools:
 
 # add the scripts, and close 'setup' call
 setup_code += """    
-      scripts=['scripts/undill','scripts/get_objgraph'])
+      scripts=['scripts/undill'+sys.version[0:3],'scripts/get_objgraph'+sys.version[0:3]])
 """
 
 # exec the 'setup' code
