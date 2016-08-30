$NetBSD: patch-setup.py,v 1.1.1.1 2011/10/28 17:00:38 jihbed Exp $

--- setup.py.orig	2011-07-27 00:20:18.000000000 +0100
+++ setup.py	2011-07-27 00:20:41.000000000 +0100
@@ -23,6 +23,7 @@
 """
 
 from distutils.core import setup
+import sys
 
 setup(
     name='AIGO',
@@ -32,7 +33,7 @@
     packages=['AIGO', 'AIGO.go', 'AIGO.utils', 'AIGO.gui', 'tests'],
     package_dir={'AIGO.gui': 'AIGO/gui'},
     package_data={'AIGO.gui': ['*.png']},    
-    scripts=['bin/AIGO-gui.py'],
+    scripts=['bin/AIGO-gui.py'+sys.version[:3]],
     url='http://pypi.python.org/pypi/AIGO/',
     license='LICENSE.txt',
     description='Analysis and Inter-comparison of Gene Ontology functional annotations',
