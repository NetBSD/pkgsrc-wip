$NetBSD$

Avoid too strict version requirements.

--- setup.py.orig	2020-12-16 21:19:50.000000000 +0000
+++ setup.py
@@ -144,13 +144,13 @@ setup(
     install_requires=[
         "attrs>=19.3.0",
         "colorama>=0.4.3",
-        "junit_xml==1.9",
+        "junit_xml>=1.9",
         "requests>=2.22.0",
         # exact version because of unstable API
-        "ruamel.yaml==0.16.10",
+        "ruamel.yaml>=0.16.10",
         "tqdm>=4.46.1",
         "packaging>=20.4",
-        "jsonschema~=3.2.0",
+        "jsonschema>=3.2.0",
     ],
     entry_points={"console_scripts": ["semgrep=semgrep.__main__:main"]},
     packages=setuptools.find_packages(),
