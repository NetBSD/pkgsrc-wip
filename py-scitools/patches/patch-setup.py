$NetBSD: patch-setup.py,v 1.1 2012/10/11 14:27:00 jihbed Exp $

--- setup.py.orig	2012-10-11 10:37:04.000000000 +0100
+++ setup.py	2012-10-11 10:37:59.000000000 +0100
@@ -9,7 +9,7 @@
 
 import os, sys, socket, re, glob, platform
 
-scripts = [os.path.join("bin", "scitools"),]
+scripts = [os.path.join("bin", "scitools"+sys.version[0:3]),]
 
 if platform.system() == "Windows" or "bdist_wininst" in sys.argv:
     # In the Windows command prompt we can't execute Python scripts
@@ -94,8 +94,8 @@
 		],
     package_data = {'': ['scitools.cfg']},
     scripts = scripts,
-    data_files=[(os.path.join("share", "man", "man1"),
-                 [os.path.join("doc", "man", "man1", "scitools.1.gz"),])],
+    data_files=[(os.path.join("man", "man1"),
+                 [os.path.join("doc", "man", "man1", "scitools.1"),])],
     )
 
 if os.path.isfile(config_file + '.cop'):
