$NetBSD$

--- setup.py.orig	2018-04-03 22:16:43.000000000 +0000
+++ setup.py
@@ -53,8 +53,6 @@ CLASSIFIERS = [
     'Topic :: Software Development :: Libraries :: Python Modules']
 
 description = "Html Content / Article Extractor, web scrapping for Python3"
-dependencies = read_file('./requirements/python').splitlines()
-test_dependencies = read_file('./requirements/python-dev').splitlines()
 
 # read long description
 try:
@@ -74,11 +72,8 @@ setup(
     url='https://github.com/goose3/goose3',
     license='Apache',
     packages=find_packages(exclude=['tests']),
-    package_data={'goose3': ['resources/images/*.txt', 'resources/text/*.txt',
-                             'requirements/python']},
+    package_data={'goose3': ['resources/images/*.txt', 'resources/text/*.txt']},
     include_package_data=True,
     zip_safe=False,
-    install_requires=dependencies,
-    test_requires=test_dependencies,
     test_suite="tests"
 )
