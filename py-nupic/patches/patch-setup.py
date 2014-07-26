$NetBSD: patch-setup.py,v 1.1 2014/07/26 09:50:17 jihbed Exp $

--- setup.py.orig	2014-07-26 10:42:53.000000000 +0100
+++ setup.py	2014-07-26 10:46:30.000000000 +0100
@@ -115,6 +115,4 @@
 
 
 # Build and setup NuPIC
-if mustBuildExtensions:
-  build_extensions_nupic()
 setup_nupic()
