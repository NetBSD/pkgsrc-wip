$NetBSD$

Python 3 compatability.

--- pystatsd/__init__.py.orig	2013-07-15 13:42:57.000000000 +0000
+++ pystatsd/__init__.py
@@ -1,4 +1,4 @@
-from statsd import Client
-from server import Server
+from pystatsd.statsd import Client
+from pystatsd.server import Server
 
 VERSION = (0, 1, 10)
