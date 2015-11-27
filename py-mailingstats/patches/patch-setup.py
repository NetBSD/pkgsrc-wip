$NetBSD$

--- setup.py.orig	2014-02-16 07:21:22.000000000 +0000
+++ setup.py
@@ -58,8 +58,8 @@ setup(
     url='http://metricsgrimoire.github.io/MailingListStats/',
     platforms = ['any'],
     packages = ['pymlstats', 'pymlstats.db'],
-    scripts = ['mlstats'],
-    data_files = [('share/man/man1',['man/mlstats.1'])],
+    scripts = ['mlstats'+sys.version[0:3]],
+    data_files = [('man/man1',['man/mlstats.1'])],
     test_suite = 'pymlstats.tests',
     extras_require = {
         'mysql': ['MySQL-python'],
