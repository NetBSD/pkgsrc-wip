$NetBSD$

Relax too strict version requirements.

--- setup.py.orig	2024-03-11 14:12:17.000000000 +0000
+++ setup.py
@@ -10,9 +10,9 @@ setup(name='tap-github',
       classifiers=['Programming Language :: Python :: 3 :: Only'],
       py_modules=['tap_github'],
       install_requires=[
-          'singer-python==5.12.1',
-          'requests==2.31.0',
-          'backoff==1.8.0'
+          'singer-python>=5.12.1',
+          'requests>=2.31.0',
+          'backoff>=1.8.0'
       ],
       extras_require={
           'dev': [
@@ -31,4 +31,4 @@ setup(name='tap-github',
           'tap_github': ['tap_github/schemas/*.json']
       },
       include_package_data=True
-)
\ No newline at end of file
+)
