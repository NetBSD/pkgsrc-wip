$NetBSD$

Avoid too strict version requirements.

--- setup.py.orig	2021-07-27 18:59:00.000000000 +0000
+++ setup.py
@@ -101,12 +101,12 @@ setuptools.setup(
         "attrs>=19.3.0",
         "colorama>=0.4.3",
         "requests>=2.22.0",
-        "ruamel.yaml>=0.16.0,<0.18",
+        "ruamel.yaml>=0.16.0",
         "tqdm>=4.46.1",
         "packaging>=20.4",
         "jsonschema~=3.2.0",
-        "wcmatch==8.2",
-        "peewee~=3.14.4",
+        "wcmatch>=8.2",
+        "peewee>=3.14.4",
         # Include 'setuptools' for 'pkg_resources' usage. We shouldn't be
         # overly prescriptive and pin the version for two reasons: 1) because
         # it may interfere with other 'setuptools' installs on the system,
