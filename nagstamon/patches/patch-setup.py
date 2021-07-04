$NetBSD$

Support NetBSD.
https://github.com/HenriWahl/Nagstamon/pull/747

--- setup.py.orig	2021-04-06 11:17:33.000000000 +0000
+++ setup.py
@@ -39,6 +39,9 @@ if OS not in ['Windows', 'Darwin']:
     # platform.dist() returns "('', '', '')" on FreeBSD
     elif OS == 'FreeBSD':
         DIST, DIST_VERSION, DIST_NAME = ('', '', '')
+    # platform.dist() does not exist on NetBSD
+    elif OS == 'NetBSD':
+        DIST, DIST_VERSION, DIST_NAME = ('', '', '')
     else:
         DIST, DIST_VERSION, DIST_NAME = platform.dist()
     NAME = NAME.lower()
