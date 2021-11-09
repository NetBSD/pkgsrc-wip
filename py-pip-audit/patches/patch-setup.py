$NetBSD$

Do not insist on one particular version.
Remove python 3.6-only dependency.

--- setup.py.orig	2021-11-09 16:12:41.000000000 +0000
+++ setup.py
@@ -30,12 +30,10 @@ setup(
     install_requires=[
         "pip-api>=0.0.23",
         "packaging>=21.0.0",
-        # TODO: Remove this once 3.7 is our minimally supported version.
-        "dataclasses>=0.6",
         "progress>=1.6",
         "resolvelib>=0.8.0",
         "html5lib>=1.1",
-        "CacheControl==0.12.6",
+        "CacheControl>=0.12.6",
         "lockfile>=0.12.2",
     ],
     extras_require={
