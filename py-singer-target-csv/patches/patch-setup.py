$NetBSD$

Relax too strict version requirements.

--- setup.py.orig	2019-04-15 16:10:06.000000000 +0000
+++ setup.py
@@ -10,8 +10,8 @@ setup(name='target-csv',
       classifiers=['Programming Language :: Python :: 3 :: Only'],
       py_modules=['target_csv'],
       install_requires=[
-          'jsonschema==2.6.0',
-          'singer-python==2.1.4',
+          'jsonschema>=2.6.0',
+          'singer-python>=2.1.4',
       ],
       entry_points='''
           [console_scripts]
