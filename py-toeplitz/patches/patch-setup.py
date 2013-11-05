$NetBSD: patch-setup.py,v 1.1 2013/11/05 19:00:52 jihbed Exp $

--- setup.py.orig	2013-11-05 19:21:06.000000000 +0100
+++ setup.py	2013-11-05 19:21:27.000000000 +0100
@@ -23,6 +23,7 @@
 .. _John Burkhardt's website: http://people.sc.fsu.edu/~jburkardt/f_src/toeplitz/toeplitz.html
 """
 
+import sys
 
 from numpy.distutils.core import Extension, setup
 
@@ -38,6 +39,6 @@
       license='MIT license',
       url='https://github.com/trichter/toeplitz',
       ext_modules=[ext],
-      scripts=['scripts/toeplitz-runtests'],
+      scripts=['scripts/toeplitz-runtests'+sys.version[0:3]],
       requires=['numpy']
       )
