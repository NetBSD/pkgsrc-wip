$NetBSD: patch-setup.py,v 1.1 2014/01/14 21:45:12 jihbed Exp $

--- setup.py.orig	2014-01-14 22:39:20.000000000 +0100
+++ setup.py	2014-01-14 22:40:13.000000000 +0100
@@ -1,3 +1,5 @@
+import sys
+
 from setuptools import setup
 
 setup(name="NetFlowVizu",
@@ -22,5 +24,5 @@
           "Topic :: Scientific/Engineering :: Visualization"
         ],
       install_requires=["lxml", "pyyaml"],
-      scripts=["net_flow_vizu_dia.py"]
+      scripts=["net_flow_vizu_dia.py"+sys.version[0:3]]
     )
