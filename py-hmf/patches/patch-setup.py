$NetBSD$

--- setup.py.orig	2016-05-02 02:31:15.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ setup(
     install_requires=["numpy>=1.6.2",
                       "scipy>=0.12.0",
                       "astropy>=1.0"],
-    scripts=["scripts/hmf", "scripts/hmf-fit"],
+    scripts=["scripts/hmf"+sys.version[0:3], "scripts/hmf-fit"+sys.version[0:3],
     author="Steven Murray",
     author_email="steven.murray@uwa.edu.au",
     description="A halo mass function calculator",
