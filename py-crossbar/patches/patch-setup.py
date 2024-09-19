$NetBSD$

--- setup.py.orig	2020-12-13 21:10:00.000000000 +0000
+++ setup.py
@@ -100,7 +100,6 @@ setup(
     },
     packages=find_packages(),
     include_package_data=True,
-    data_files=[('.', ['crossbar/LEGAL', 'crossbar/LICENSE', 'crossbar/LICENSE-FOR-API', 'crossbar/LICENSES-OSS'])],
     zip_safe=False,
     python_requires='>=3.6',
 
