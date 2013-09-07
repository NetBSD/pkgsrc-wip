$NetBSD: patch-setup.py,v 1.1 2013/09/07 19:53:40 jihbed Exp $

--- setup.py.orig	2013-06-16 19:55:08.000000000 +0000
+++ setup.py	2013-09-07 16:22:08.000000000 +0000
@@ -1,5 +1,6 @@
 # -*- coding:utf8 -*-
 import ez_setup
+import sys
 ez_setup.use_setuptools()
 from setuptools import setup
 from glob import glob
@@ -31,12 +32,12 @@
         ],
         'gui_scripts': [
             'epigrass = Epigrass.epigrass:main',
-            'epgeditor= Epigrass.epgeditor:main', 
-            'neteditor= Epigrass.neteditor:main'
+            'epgeditor = Epigrass.epgeditor:main', 
+            'neteditor = Epigrass.neteditor:main'
         ]
     }, 
 
     include_package_data = True,
     package_data = {'':['INSTALL','README','COPYING','epigrass.desktop','*.rst','*.tex','*.png','*.jpg']},
-    #data_files = [('/usr/share/pixmaps',['egicon.png']),('/usr/share/doc/epigrass/demos',demos),('/usr/share/doc/epigrass/',['docs/build/latex/Epigrass.pdf']),('/usr/share/applications',['epigrass.desktop'])]
+    data_files = [('/usr/pkg/share/pixmaps',['egicon.png']),('/usr/pkg/share/doc/epigrass/demos',demos),('/usr/pkg/share/doc/epigrass/',['docs/build/latex/Epigrass.pdf']),('/usr/pkg/share/applications',['epigrass.desktop'])]
     )
