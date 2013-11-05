$NetBSD: patch-setup.py,v 1.1 2013/11/05 17:46:51 jihbed Exp $

--- setup.py.orig	2013-10-03 23:32:01.000000000 +0100
+++ setup.py	2013-11-05 17:18:28.000000000 +0100
@@ -1,5 +1,7 @@
 #!/usr/bin/env python
 
+import sys
+
 from distutils.core import setup
 import versioneer
 
@@ -15,7 +17,7 @@
       author='L. Amber Wilcox-O\'Hearn',
       author_email='amber@cs.toronto.edu',
       url='https://github.com/lamber/recluse',
-      scripts=['scripts/nltkbasedsegmentertokeniserrunner'],
+      scripts=['scripts/nltkbasedsegmentertokeniserrunner'+sys.version[0:3]],
       packages=['recluse', 'recluse.test'],
       package_data={"recluse.test": ["data/*"]},
       license='COPYING',
