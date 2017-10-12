$NetBSD$

--- setup.py.orig	2017-07-31 18:28:59.000000000 +0000
+++ setup.py
@@ -107,8 +107,6 @@ setup(
     keywords='Robinhood trade API',
     packages=find_packages(),
     data_files=[
-        ('docs', include_all_subfiles('docs')),
-        ('tests', include_all_subfiles('tests'))
     ],
     install_requires=get_requirements(),
     tests_require=get_requirements(True),
