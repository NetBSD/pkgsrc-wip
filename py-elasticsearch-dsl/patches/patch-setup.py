$NetBSD$

remove bounds

--- setup.py.orig	2021-07-15 15:32:37.000000000 +0000
+++ setup.py
@@ -31,7 +31,7 @@ f.close()
 install_requires = [
     "six",
     "python-dateutil",
-    "elasticsearch>=7.0.0,<8.0.0",
+    "elasticsearch",
     # ipaddress is included in stdlib since python 3.3
     'ipaddress; python_version<"3.3"',
 ]
