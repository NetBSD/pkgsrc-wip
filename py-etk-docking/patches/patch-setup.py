$NetBSD: patch-setup.py,v 1.1 2012/10/03 22:30:36 jihbed Exp $

--- setup.py.orig	2012-10-03 23:20:30.000000000 +0100
+++ setup.py	2012-10-03 23:21:04.000000000 +0100
@@ -94,8 +94,8 @@
 
       packages = find_packages('lib'),
       package_dir = {'': 'lib'},
-      data_files = get_data_files(('doc/examples', 'doc/examples', '*.py'),
-                                  ('doc/reference', 'doc/reference/build/html', '*')),
+      data_files = get_data_files(('examples', 'examples', '*.py'),
+                                  ('reference', 'reference/build/html', '*')),
 
       tests_require = ['nose'],
       test_suite = 'nose.collector')
