$NetBSD$

--- setup.py.orig	2016-04-21 12:04:08.000000000 +0000
+++ setup.py
@@ -5,6 +5,7 @@
 #   * Add download_url
 
 import os
+import sys
 import subprocess
 import codecs
 from fnmatch import fnmatchcase
@@ -174,7 +175,7 @@ def do_setup():
               'theano.misc': ['*.sh'],
               'theano.d3viz' : ['html/*','css/*','js/*']
           },
-          scripts=['bin/theano-cache', 'bin/theano-nose', 'bin/theano-test'],
+          scripts=['bin/theano-cache'+sys.version[0:3], 'bin/theano-nose'+sys.version[0:3], 'bin/theano-test'+sys.version[0:3]],
           keywords=' '.join([
               'theano', 'math', 'numerical', 'symbolic', 'blas',
               'numpy', 'gpu', 'autodiff', 'differentiation'
