$NetBSD$

Setuptools will try and download these versions... tell it not to.

--- python/setup.py.orig	2024-01-30 14:19:14.017798084 +0000
+++ python/setup.py
@@ -492,7 +492,7 @@ setup(
                                  'pyarrow/_generated_version.py'),
         'version_scheme': guess_next_dev_version
     },
-    setup_requires=['setuptools_scm < 8.0.0', 'cython >= 0.29.31'] + setup_requires,
+    setup_requires=[],
     install_requires=install_requires,
     tests_require=['pytest', 'pandas', 'hypothesis'],
     python_requires='>=3.8',
