$NetBSD$

Install rsf.py.

--- setup.py.orig	2018-07-09 19:09:31.000000000 +0000
+++ setup.py
@@ -15,6 +15,7 @@ setup(
     download_url="https://github.com/threat9/routersploit/",
     packages=find_packages(),
     include_package_data=True,
+    scripts=('rsf.py',),
     entry_points={},
     install_requires=[
         "future",
