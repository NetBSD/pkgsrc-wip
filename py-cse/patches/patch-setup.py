$NetBSD: patch-setup.py,v 1.1 2013/09/07 21:35:24 jihbed Exp $

--- setup.py.orig	2013-08-27 19:31:16.000000000 +0000
+++ setup.py	2013-09-07 21:23:40.000000000 +0000
@@ -1,5 +1,6 @@
 from distutils.core import setup
 import os
+import sys
 from pycse import __version__
   
 setup(name = 'pycse',
@@ -11,7 +12,7 @@
       license='GPL',
       platforms=['linux'],
       packages=['pycse'],
-      scripts=['pycse/publish.py'],
+      scripts=['pycse/publish.py'+sys.version[0:3]],
       long_description='''\
 python computations in science and engineering
 ===============================================
