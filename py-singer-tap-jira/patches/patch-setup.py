$NetBSD$

Relax too strict version requirements.

--- setup.py.orig	2024-01-23 21:36:35.000000000 +0000
+++ setup.py
@@ -9,8 +9,8 @@ setup(name="tap-jira",
       classifiers=["Programming Language :: Python :: 3 :: Only"],
       py_modules=["tap_jira"],
       install_requires=[
-          "singer-python==6.0.0",
-          "requests==2.31.0",
+          "singer-python>=6.0.0",
+          "requests>=2.31.0",
           "dateparser"
       ],
       extras_require={
