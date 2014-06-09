$NetBSD: patch-setup.py,v 1.1 2014/06/09 21:12:57 jihbed Exp $
--- setup.py.orig	2014-06-09 21:01:41.000000000 +0100
+++ setup.py	2014-06-09 21:07:15.000000000 +0100
@@ -7,6 +7,7 @@
 
 from __future__ import with_statement, absolute_import
 import os
+import sys
 
 # set version numbers
 stable_version = '0.2.1'
@@ -268,7 +269,7 @@
 
 # add the scripts, and close 'setup' call
 setup_code += """    
-      scripts=['scripts/unpickle.py','scripts/get_objgraph.py'])
+      scripts=['scripts/unpickle.py'+sys.version[0:3],'scripts/get_objgraph.py'+sys.version[0:3]])
 """
 
 # exec the 'setup' code
