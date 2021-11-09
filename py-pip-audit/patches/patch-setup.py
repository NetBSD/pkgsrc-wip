$NetBSD$

Fix dataclasses dependency
https://github.com/trailofbits/pip-audit/pull/114/files

Do not insist on one particular version of CacheControl.

--- setup.py.orig	2021-11-09 16:12:41.000000000 +0000
+++ setup.py
@@ -30,12 +30,12 @@ setup(
     install_requires=[
         "pip-api>=0.0.23",
         "packaging>=21.0.0",
         # TODO: Remove this once 3.7 is our minimally supported version.
-        "dataclasses>=0.6",
+        "dataclasses>=0.6; python_version < '3.7'",
         "progress>=1.6",
         "resolvelib>=0.8.0",
         "html5lib>=1.1",
-        "CacheControl==0.12.6",
+        "CacheControl>=0.12.6",
         "lockfile>=0.12.2",
     ],
     extras_require={
