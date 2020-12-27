$NetBSD$

--- setup.py.orig	2019-05-31 18:29:30.000000000 +0000
+++ setup.py
@@ -43,7 +43,7 @@ def version():
 
 setup(
     name='flatbuffers',
-    version=version(),
+    version= 1.12,
     license='Apache 2.0',
     author='FlatBuffers Contributors',
     author_email='me@rwinslow.com',
@@ -68,4 +68,4 @@ setup(
         'Documentation': 'https://google.github.io/flatbuffers/',
         'Source': 'https://github.com/google/flatbuffers',
     },
-)
\ Pas de fin de ligne à la fin du fichier
+)
