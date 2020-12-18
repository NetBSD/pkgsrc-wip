$NetBSD$

--- setup.py.orig	2020-12-08 19:14:16.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 #!/usr/bin/env python
 import logging
 import os
+import sys
 from importlib import util
 from os import path
 
@@ -100,7 +101,7 @@ setup(
     author_email="meet@bridgecrew.io",
     url="https://github.com/bridgecrewio/checkov",
     packages=setuptools.find_packages(exclude=["tests*","integration_tests*"]),
-    scripts=["bin/checkov","bin/checkov.cmd"],
+    scripts=["bin/checkov"+sys.version[0:3]],
     long_description=long_description,
     long_description_content_type="text/markdown",
     classifiers=[
