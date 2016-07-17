$NetBSD$

--- setup.py.orig	2015-03-25 10:28:09.000000000 +0000
+++ setup.py
@@ -53,7 +53,6 @@ setup(
     url = "https://github.com/benediktschmitt/py-filelock",
     download_url = "https://github.com/benediktschmitt/py-filelock/archive/master.zip",
     py_modules = ["filelock"],
-    data_files = [("", ["LICENSE.rst", "README.rst"])],
     license = license_,
     classifiers = [
         "License :: Public Domain",
