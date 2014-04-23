$NetBSD: patch-setup.py,v 1.1 2014/04/23 19:50:38 nros Exp $
* remove non-versioned file. The console command for editorconfig-core 
  is in the editorconfig-core package. Removing this file removes the 
  conflict that this package would have with the editor-config-core 
  package.
--- setup.py.orig	2014-04-23 18:53:35.000000000 +0000
+++ setup.py
@@ -10,9 +10,4 @@ setup(
     license='LICENSE.txt',
     description='EditorConfig File Locator and Interpreter for Python',
     long_description=open('README.rst').read(),
-    entry_points = {
-        'console_scripts': [
-            'editorconfig = editorconfig.main:main',
-        ]
-    },
 )
