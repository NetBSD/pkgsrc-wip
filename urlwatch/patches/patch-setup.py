$NetBSD$

Use the pkgsrc directory structure.

--- setup.py.orig	2022-03-15 13:44:20.000000000 +0000
+++ setup.py
@@ -25,16 +25,16 @@ m['package_dir'] = {'': 'lib'}
 m['packages'] = ['urlwatch']
 m['python_requires'] = '>=3.6'
 m['data_files'] = [
-    ('share/man/man1', [
+    (os.getenv('PKGMANDIR') + '/man1', [
         'share/man/man1/urlwatch.1',
     ]),
-    ('share/man/man5', [
+    (os.getenv('PKGMANDIR') + '/man5', [
         'share/man/man5/urlwatch-config.5',
         'share/man/man5/urlwatch-filters.5',
         'share/man/man5/urlwatch-jobs.5',
         'share/man/man5/urlwatch-reporters.5',
     ]),
-    ('share/man/man7', [
+    (os.getenv('PKGMANDIR') + '/man7', [
         'share/man/man7/urlwatch-cookbook.7',
         'share/man/man7/urlwatch-deprecated.7',
         'share/man/man7/urlwatch-intro.7',
