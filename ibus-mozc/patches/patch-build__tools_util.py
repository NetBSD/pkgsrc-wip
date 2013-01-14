$NetBSD: patch-build__tools_util.py,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* Treat FreeBSD/NetBSD like OS X.

--- build_tools/util.py.orig	2012-08-31 05:37:06.000000000 +0000
+++ build_tools/util.py
@@ -54,7 +54,7 @@ def IsMac():
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and (os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' or os.uname()[0] == 'NetBSD')
 
 
 def GetNumberOfProcessors():
