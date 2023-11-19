$NetBSD$

--- python/setup.py.orig	2023-11-19 21:12:52.091720220 +0000
+++ python/setup.py
@@ -492,7 +492,7 @@ setup(
                                  'pyarrow/_generated_version.py'),
         'version_scheme': guess_next_dev_version
     },
-    setup_requires=['setuptools_scm < 8.0.0', 'cython >= 0.29.31'] + setup_requires,
+    setup_requires=['setuptools_scm < 9.0.0', 'cython >= 0.29.31'] + setup_requires,
     install_requires=install_requires,
     tests_require=['pytest', 'pandas', 'hypothesis'],
     python_requires='>=3.8',
