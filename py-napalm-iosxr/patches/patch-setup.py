$NetBSD$

Don't install test directory.

--- setup.py.orig	2017-02-08 20:16:47.000000000 +0000
+++ setup.py
@@ -13,7 +13,7 @@ reqs = [str(ir.req) for ir in install_re
 setup(
     name="napalm-iosxr",
     version="0.4.8",
-    packages=find_packages(),
+    packages=find_packages(exclude=["test", "test.*"]),
     author="David Barroso, Mircea Ulinic",
     author_email="dbarrosop@dravetech.com, mircea@cloudflare.com",
     description="Network Automation and Programmability Abstraction Layer with Multivendor support",
