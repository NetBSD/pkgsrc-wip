$NetBSD$

Allow to use newer versions of dependencies.

--- setup.py.orig	2018-07-16 14:49:07.000000000 +0000
+++ setup.py
@@ -166,9 +166,9 @@ def _filter_requirements(lines_iter, fil
 
 
 REQ_UPPER_BOUNDS = {
-    'bcolz': '<1',
-    'pandas': '<=0.22',
-    'networkx': '<2.0',
+    #'bcolz': '<1',
+    #'pandas': '<=0.22',
+    #'networkx': '<2.0',
 }
 
 
