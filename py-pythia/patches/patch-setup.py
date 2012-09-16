$NetBSD: patch-setup.py,v 1.1 2012/09/16 18:01:30 jihbed Exp $

--- setup.py.orig	2012-09-16 18:43:20.000000000 +0100
+++ setup.py	2012-09-16 18:44:06.000000000 +0100
@@ -1,3 +1,4 @@
+import sys
 
 try:
     from merlin import setup, find_packages
@@ -17,7 +18,7 @@
     name = 'pythia', 
     version = '0.8.1.14',
 
-    scripts = ['bin/idd.py', 'bin/ipad.py', 'bin/journald.py'],
+    scripts = ['bin/idd.py'+sys.version[0:3], 'bin/ipad.py'+sys.version[0:3], 'bin/journald.py'+sys.version[0:3]],
 
     zip_safe = False,
     packages = find_packages(),
