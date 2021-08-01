$NetBSD$

Explicitly add requirements (the package does not contain any requirements.txt so
get_requirements() will fail).

The cryptography dependency is relaxed because cryptography-3.4.7 or
newer are not yet present in pkgsrc.

--- setup.py.orig	2021-04-26 11:48:30.000000000 +0000
+++ setup.py
@@ -58,7 +58,13 @@ setup(
     url='https://github.com/italia/spid-compliant-certificates-python',
 
     packages=find_packages(exclude=['bin']),
-    install_requires=get_requirements(),
+    install_requires=[
+        "cryptography>=3.3.0",
+        "iso3166>=1.0.1"
+        "packaging>=20.9"
+        "requests>=2.25.1"
+        "ruamel.yaml>=0.17.4",
+    ],
     scripts=['bin/spid-compliant-certificates'],
     python_requires='>=3.6',
 )
