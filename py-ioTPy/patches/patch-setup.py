$NetBSD$

--- setup.py.orig	2020-07-11 20:59:04.000000000 +0000
+++ setup.py
@@ -4,9 +4,6 @@ import os
 with open("README.md", "r") as fh:
     long_description = fh.read()
 
-with open("requirements.txt") as f:
-    REQ = f.read().splitlines()
-
 # get __version__ from _version.py
 ver_file = os.path.join('IoTPy', '_version.py')
 with open(ver_file) as f:
@@ -40,6 +37,5 @@ setup(
     url="https://github.com/AssembleSoftware/IoTPy",
     classifiers= CLASSIFIERS,
     packages = find_packages(),
-    install_requires = REQ
 )
 
