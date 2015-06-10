$NetBSD: patch-setup.py,v 1.1 2015/06/10 22:11:11 jihbed Exp $

--- setup.py.orig	2014-10-31 19:40:05.000000000 +0000
+++ setup.py
@@ -64,7 +64,7 @@ def setup_cclib():
         platforms = ["Any."],
         packages = cclib_packages,
         package_dir = { 'cclib':'src/cclib' },
-        scripts = ["src/scripts/ccget", "src/scripts/cda"],
+        scripts = ["src/scripts/ccget"+sys.version[0:3], "src/scripts/cda"+sys.version[0:3]],
     )
 
 
