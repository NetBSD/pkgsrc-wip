$NetBSD: patch-setup.py,v 1.1 2014/01/14 17:52:32 jihbed Exp $

--- setup.py.orig	2014-01-14 18:46:14.000000000 +0100
+++ setup.py	2014-01-14 18:46:51.000000000 +0100
@@ -1,6 +1,9 @@
+import sys
+
 from distutils.core import setup, Extension
 from distutils.sysconfig import *
 from distutils.util import *
+
 import numpy
 
         
@@ -24,7 +27,7 @@
     ]
 
 packages=['minepy']
-scripts = ["minepy/scripts/mine"]
+scripts = ["minepy/scripts/mine"+sys.version[0:3]]
 data_files = []
 
 classifiers = [
