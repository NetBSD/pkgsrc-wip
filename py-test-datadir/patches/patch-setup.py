$NetBSD$

--- setup.py.orig	2019-10-22 13:04:06.000000000 +0000
+++ setup.py
@@ -18,7 +18,6 @@ setup(
     },
     package_dir={"": "src"},
     install_requires=['pytest>=2.7.0'],
-    data_files = [("", ["LICENSE"])],
     author='Gabriel Reis',
     author_email='gabrielcnr@gmail.com',
     description='pytest plugin for test data directories and files',
