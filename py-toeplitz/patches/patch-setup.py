$NetBSD: patch-setup.py,v 1.2 2013/11/30 16:08:02 jihbed Exp $

--- setup.py.orig	2013-11-30 16:58:45.000000000 +0100
+++ setup.py	2013-11-30 16:59:12.000000000 +0100
@@ -1,4 +1,6 @@
 #!/usr/bin/env python
+
+import sys
 from numpy.distutils.core import Extension, setup
 
 VERSION='0.1.2'
@@ -22,7 +24,7 @@
       license='MIT',
       url='https://github.com/trichter/toeplitz',
       ext_modules=[ext],
-      scripts=['scripts/toeplitz-runtests'],
+      scripts=['scripts/toeplitz-runtests'+sys.version[0:3]],
       requires=['numpy'],
       include_package_data=True
       )
