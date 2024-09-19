$NetBSD: patch-setup.py,v 1.1 2014/05/09 23:11:15 jihbed Exp $

--- setup.py.orig	2014-05-10 00:04:18.000000000 +0100
+++ setup.py	2014-05-10 00:04:46.000000000 +0100
@@ -2,6 +2,8 @@
 # -*- coding: utf-8 -*-
 # flake8: noqa
 
+import sys
+
 from distutils.core import setup
 
 long_description = open('README.rst').read()
@@ -12,7 +14,7 @@
     name = "bloscpack",
     version = __version__,
     packages = ['bloscpack'],
-    scripts = ['blpk'],
+    scripts = ['blpk'+sys.version[0:3]],
     author = "Valentin Haenel",
     author_email = "valentin@haenel.co",
     description = "Command line interface to and serialization format for Blosc",
