$NetBSD: patch-setup.py,v 1.1.1.1 2012/08/25 16:59:53 jihbed Exp $
--- setup.py.orig	2012-07-26 21:37:51.000000000 +0100
+++ setup.py	2012-07-26 21:38:47.000000000 +0100
@@ -1,5 +1,7 @@
 from distutils.core import setup
 
+import sys
+
 classifiers = [
     'Development Status :: 3 - Alpha',
     'Intended Audience :: Developers',
@@ -21,6 +23,6 @@
     url = "http://github.com/nicferrier/lxmlproc",
     download_url="http://github.com/nicferrier/lxmlproc/downloads",
     platforms = ["any"],
-    scripts=['src/lxmlproc'],
+    scripts=['src/lxmlproc'+sys.version[0:3]],
     classifiers =  classifiers
     )
