$NetBSD$

Do not be overly restrictive.

--- setup.py.orig	2018-07-12 14:38:23.000000000 +0000
+++ setup.py
@@ -25,7 +25,7 @@ setup(name='subsync',
           'numpy',
           'matplotlib',
           'librosa',
-          'h5py==2.8.0rc1',
+          'h5py',
           'pysrt',
       ],
       zip_safe=False)
