$NetBSD$

Fix man path.

--- setup.py.orig	2015-12-12 22:27:05.000000000 +0000
+++ setup.py
@@ -35,7 +35,7 @@ setup(
             'src/depdiagram-generate-all',
         ],
         data_files= [
-            (os.path.join('share', 'man', 'man1'), ['docs/kgenapidox.1',
+            (os.path.join('man', 'man1'), ['docs/kgenapidox.1',
                 'docs/kgenframeworksapidox.1', 'docs/depdiagram-prepare.1',
                 'docs/depdiagram-generate.1',
                 'docs/depdiagram-generate-all.1'])],
