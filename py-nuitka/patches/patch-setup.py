$NetBSD: patch-setup.py,v 1.1 2015/08/01 22:15:24 jihbed Exp $

--- setup.py.orig	2015-07-31 15:53:31.000000000 +0000
+++ setup.py
@@ -20,7 +20,7 @@ import sys, os
 
 os.chdir(os.path.dirname(__file__) or ".")
 
-scripts = ["bin/nuitka", "bin/nuitka-run"]
+scripts = ["bin/nuitka"+sys.version[0:3]]
 
 # For Windows, there are batch files to launch Nuitka.
 if os.name == "nt":
