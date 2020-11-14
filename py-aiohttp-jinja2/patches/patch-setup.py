$NetBSD$

--- setup.py.orig	2020-11-12 10:24:13.000000000 +0000
+++ setup.py
@@ -38,7 +38,7 @@ setup(
     description=(
         "jinja2 template renderer for aiohttp.web " "(http server for asyncio)"
     ),
-    long_description="\n\n".join((read("README.rst"), read("CHANGES.rst"))),
+    long_description="\n\n".join((read("README.rst"))),
     classifiers=[
         "License :: OSI Approved :: Apache Software License",
         "Intended Audience :: Developers",
