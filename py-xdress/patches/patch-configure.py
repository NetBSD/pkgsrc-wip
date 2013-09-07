$NetBSD: patch-configure.py,v 1.1 2013/09/07 18:56:46 jihbed Exp $

--- configure.py.orig	2013-09-07 17:02:42.000000000 +0000
+++ configure.py	2013-09-07 17:03:28.000000000 +0000
@@ -120,7 +120,7 @@
             "Topic :: Software Development :: Compilers",
             "Topic :: Utilities",
         ],
-        "data_files": [("", ['license', 'configure.py']),],
+       # "data_files": [("", ['license', 'configure.py']),],
     }
     # changing dirs for virtualenv
     cwd = os.getcwd()
