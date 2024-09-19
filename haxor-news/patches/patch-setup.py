$NetBSD$

Do not install tests. They aren't isolated in haxor_news subdirectory and so can
pollute ${PYSITELIB}.

--- setup.py.orig	2017-04-09 02:26:43.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ setup(
             'hn = haxor_news.main_cli:cli'
         ]
     },
-    packages=find_packages(),
+    packages=find_packages(exclude=["tests", "tests.*"]),
     scripts=[],
     name='haxor-news',
     classifiers=[
