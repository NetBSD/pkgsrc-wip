$NetBSD$

--- setup.py.orig	2015-09-13 02:58:12.000000000 +0000
+++ setup.py
@@ -19,8 +19,8 @@ if sys.platform == 'win32':
     ]
 else:
     scripts = [
-        'bin/activate',
-        'bin/deactivate',
+        'bin/activate'+sys.version[0:3],
+        'bin/deactivate'+sys.version[0:3],
     ]
 
 setup(
@@ -50,7 +50,7 @@ setup(
         'conda_env.utils',
     ],
     scripts=[
-        'bin/conda-env',
+        'bin/conda-env'+sys.version[0:3],
     ] + scripts,
     package_data={},
 )
