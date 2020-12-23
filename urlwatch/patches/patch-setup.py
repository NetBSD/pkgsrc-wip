$NetBSD$

Use the pkgsrc directory structure.

--- setup.py.orig	2020-12-19 11:27:43.000000000 +0000
+++ setup.py
@@ -24,8 +24,8 @@ m['package_dir'] = {'': 'lib'}
 m['packages'] = ['urlwatch']
 m['python_requires'] = '>=3.6'
 m['data_files'] = [
-    ('share/man/man1', ['share/man/man1/urlwatch.1']),
-    ('share/urlwatch/examples', [
+    (os.getenv('PKGMANDIR') + '/man1', ['share/man/man1/urlwatch.1']),
+    ('share/examples/urlwatch', [
         'share/urlwatch/examples/hooks.py.example',
         'share/urlwatch/examples/urls.yaml.example',
     ]),
