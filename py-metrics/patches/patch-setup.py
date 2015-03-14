$NetBSD: patch-setup.py,v 1.1 2015/03/14 17:49:21 jihbed Exp $

--- setup.py.orig	2008-07-24 04:51:45.000000000 +0000
+++ setup.py
@@ -1,5 +1,7 @@
 #!/usr/bin/python
 
+import sys
+
 from distutils.core import setup
 
 setup (name = "PyMetrics",
@@ -9,5 +11,5 @@ setup (name = "PyMetrics",
        description = "PyMetrics produces metrics for Python programs",
        url = "http://sourceforge.net/projects/pymetrics/",
        packages = ['PyMetrics'],
-       scripts = ['pymetrics']
+       scripts = ['pymetrics'+sys.version[0:3]]
 )
