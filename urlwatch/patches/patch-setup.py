$NetBSD$

Use the pkgsrc directory structure.

--- setup.py.orig	2016-07-12 18:58:17.000000000 +0000
+++ setup.py
@@ -18,8 +18,8 @@ m['scripts'] = ['urlwatch']
 m['package_dir'] = {'': 'lib'}
 m['packages'] = ['urlwatch']
 m['data_files'] = [
-    ('share/man/man1', ['share/man/man1/urlwatch.1']),
-    ('share/urlwatch/examples', [
+    (os.getenv('PKGMANDIR') + '/man1', ['share/man/man1/urlwatch.1']),
+    ('share/examples/urlwatch', [
         'share/urlwatch/examples/hooks.py.example',
         'share/urlwatch/examples/urls.yaml.example',
     ]),
