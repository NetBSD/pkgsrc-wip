$NetBSD$

Fix the case for an empty dirname.

--- setup.py.orig	2016-06-14 18:14:55.000000000 +0000
+++ setup.py
@@ -10,7 +10,7 @@ import re
 
 PACKAGE_NAME = 'urlwatch'
 DEPENDENCIES = ['minidb', 'PyYAML', 'requests']
-HERE = os.path.dirname(__file__)
+HERE = os.path.dirname(os.path.abspath(__file__))
 
 # Assumptions:
 #  1. Package name equals main script file name (and only one script)
