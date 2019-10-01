$NetBSD$

--- iniparse/configparser.py.orig	2019-10-01 14:22:56.883205200 +0000
+++ iniparse/configparser.py
@@ -0,0 +1,7 @@
+try:
+    from ConfigParser import *
+    # not all objects get imported with __all__
+    from ConfigParser import Error, InterpolationMissingOptionError
+except ImportError:
+    from configparser import *
+    from configparser import Error, InterpolationMissingOptionError
