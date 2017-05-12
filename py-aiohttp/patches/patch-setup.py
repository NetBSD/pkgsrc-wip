$NetBSD$

Avoid too strict version requirements.

--- setup.py.orig	2017-04-12 22:38:22.000000000 +0000
+++ setup.py
@@ -58,7 +58,7 @@ with codecs.open(os.path.join(os.path.ab
 
 
 install_requires = ['chardet', 'multidict>=2.1.4',
-                    'async_timeout>=1.2.0', 'yarl>=0.10.0,<0.11']
+                    'async_timeout>=1.2.0', 'yarl>=0.10.0']
 
 if sys.version_info < (3, 4, 2):
     raise RuntimeError("aiohttp requires Python 3.4.2+")
