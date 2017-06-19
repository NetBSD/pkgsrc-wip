$NetBSD$

Don't install tests.

--- setup.py.orig	2017-04-25 18:40:15.000000000 +0000
+++ setup.py
@@ -13,7 +13,7 @@ reqs = [str(ir.req) for ir in install_re
 setup(
     name="napalm-nxos",
     version="0.5.2",
-    packages=find_packages(),
+    packages=find_packages(exclude=["test", "test.*"]),
     author="David Barroso",
     author_email="dbarrosop@dravetech.com",
     description="Network Automation and Programmability Abstraction Layer with Multivendor support",
