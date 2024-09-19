$NetBSD$

--- setup.py.orig	2018-11-27 23:49:28.000000000 +0000
+++ setup.py
@@ -59,13 +59,6 @@ setup(
     packages=['traces'],
     package_dir={'traces': 'traces'},
     include_package_data=True,
-    install_requires=read_dependencies('python.txt'),
-    extras_require={
-        'test': read_dependencies('python-test.txt'),
-        'doc': read_dependencies('python-doc.txt'),
-        'dev': read_dependencies('python-dev.txt'),
-        'pandas': ['pandas'],
-    },
     license="MIT license",
     zip_safe=False,
     keywords='traces',
