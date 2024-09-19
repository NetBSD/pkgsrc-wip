$NetBSD$

Avoid too strict version requirements.

--- setup.py.orig	2016-12-02 23:14:28.000000000 +0000
+++ setup.py
@@ -283,22 +283,22 @@ setup_dict = dict(
     ],
     packages=find_packages(exclude=(TESTS_DIRECTORY,)),
     install_requires=[
-        'six >= 1.10, < 2',
-        'future >= 0.16, < 1',
-        'requests >= 2.12, < 3',
-        'oauthlib >= 2.0, < 3',
-        'requests_oauthlib >= 0.7, < 1',
-        'uritemplate >= 0.6, < 1',
-        'simplejson >= 3.10, < 4',
-        'voluptuous >= 0.9, < 1'
+        'six >= 1.10',
+        'future >= 0.16',
+        'requests >= 2.12',
+        'oauthlib >= 2.0',
+        'requests_oauthlib >= 0.7',
+        'uritemplate >= 0.6',
+        'simplejson >= 3.10',
+        'voluptuous >= 0.9'
         # your module dependencies
     ] + python_version_specific_requires,
     # Allow tests to be run with `python setup.py test'.
     tests_require=[
-        'pytest >= 2.7, < 3',
-        'mock >= 1.0, < 2',
-        'flake8 >= 2.4, < 3',
-        'httpretty >= 0.8, < 1',
+        'pytest >= 2.7',
+        'mock >= 1.0',
+        'flake8 >= 2.4',
+        'httpretty >= 0.8',
     ],
     cmdclass={'test': TestAllCommand},
     zip_safe=False,  # don't use eggs
