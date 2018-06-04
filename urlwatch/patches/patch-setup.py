$NetBSD$

Use the pkgsrc directory structure.

--- setup.py.orig	2018-06-03 12:42:56.000000000 +0000
+++ setup.py
@@ -22,8 +22,8 @@ m['package_dir'] = {'': 'lib'}
 m['packages'] = ['urlwatch']
 m['python_requires'] = '>3.3.0'
 m['data_files'] = [
-    ('share/man/man1', ['share/man/man1/urlwatch.1']),
-    ('share/urlwatch/examples', [
+    (os.getenv('PKGMANDIR') + '/man1', ['share/man/man1/urlwatch.1']),
+    ('share/examples/urlwatch', [
         'share/urlwatch/examples/hooks.py.example',
         'share/urlwatch/examples/urls.yaml.example',
     ]),
