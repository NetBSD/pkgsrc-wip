$NetBSD$

--- setup.py.orig	2014-07-04 14:47:53.000000000 +0000
+++ setup.py
@@ -78,11 +78,11 @@ setup (name = 'spams',
 #       scripts = ['test_spams.py'],
        data_files = [
         ('test',['test_spams.py', 'test_decomp.py', 'test_dictLearn.py', 'test_linalg.py', 'test_prox.py', 'test_utils.py']),
-        ('doc',['doc_spams.pdf', 'python-interface.pdf']), 
-        ('doc/sphinx/_sources',mkhtml('_sources')),
-        ('doc/sphinx/_static',mkhtml('_static')),
-        ('doc/sphinx',mkhtml()),
-        ('doc/html',mkhtml(base = 'html')),
+        ('share/doc',['doc_spams.pdf', 'python-interface.pdf']), 
+        ('share/doc/sphinx/_sources',mkhtml('_sources')),
+        ('share/doc/sphinx/_static',mkhtml('_static')),
+        ('share/doc/sphinx',mkhtml()),
+        ('share/doc/html',mkhtml(base = 'html')),
         ('extdata',['boat.png', 'lena.png'])
         ],
 )
