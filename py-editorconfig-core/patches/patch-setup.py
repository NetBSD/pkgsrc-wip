$NetBSD: patch-setup.py,v 1.2 2014/11/19 20:12:30 nros Exp $

* remove non-versioned file. The console command for editorconfig-core 
  is in the editorconfig-core package. Removing this file removes the 
  conflict that this package would have with the editorconfig-core 
  package.

--- setup.py.orig	2014-11-19 19:02:21.000000000 +0000
+++ setup.py
@@ -10,11 +10,6 @@ setup(
     license='LICENSE.txt',
     description='EditorConfig File Locator and Interpreter for Python',
     long_description=open('README.rst').read(),
-    entry_points = {
-        'console_scripts': [
-            'editorconfig = editorconfig.main:main',
-        ]
-    },
     classifiers=[
         'Operating System :: OS Independent',
         'Programming Language :: Python',
