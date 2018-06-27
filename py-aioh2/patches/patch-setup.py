$NetBSD$

Avoid too strict version requirements.

--- setup.py.orig	2018-02-05 02:32:51.000000000 +0000
+++ setup.py
@@ -12,8 +12,8 @@ with open('HISTORY.rst') as history_file
     history = history_file.read()
 
 requirements = [
-    'h2 >=3, <4',
-    'priority==1.3.0',
+    'h2 >=3',
+    'priority >=1.3.0',
 ]
 
 test_requirements = [
