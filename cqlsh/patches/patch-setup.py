$NetBSD$

Remove unused `cql' dependency.

--- setup.py.orig	2021-03-09 21:08:45.000000000 +0000
+++ setup.py
@@ -4,7 +4,6 @@ from setuptools import setup
 setup(
     name="cqlsh",
     install_requires=[
-        "cql",
         "cassandra-driver",
         "six",
     ],
