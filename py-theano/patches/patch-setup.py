$NetBSD$

--- setup.py.orig	2015-03-26 21:43:05.000000000 +0000
+++ setup.py
@@ -180,7 +180,7 @@ def do_setup():
                    '*.h', 'ChangeLog'],
               'theano.misc': ['*.sh']
           },
-          scripts=['bin/theano-cache', 'bin/theano-nose', 'bin/theano-test'],
+          scripts=['bin/theano-cache'+sys.version[0:3], 'bin/theano-nose'+sys.version[0:3], 'bin/theano-test'+sys.version[0:3]],
           keywords=' '.join([
               'theano', 'math', 'numerical', 'symbolic', 'blas',
               'numpy', 'gpu', 'autodiff', 'differentiation'
