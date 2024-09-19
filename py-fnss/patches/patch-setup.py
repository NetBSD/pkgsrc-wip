$NetBSD: patch-setup.py,v 1.1 2014/06/20 18:20:42 jihbed Exp $

--- setup.py.orig	2014-04-17 00:22:25.000000000 +0100
+++ setup.py	2014-06-20 19:06:10.000000000 +0100
@@ -85,8 +85,8 @@
             'fnss.adapters',
         ],
         scripts=[
-            'bin/fnss-troubleshoot',
-            'bin/mn-fnss'
+            'bin/fnss-troubleshoot'+sys.version[:3],
+            'bin/mn-fnss'+sys.version[:3]
         ],
         url=release.url,
         download_url=release.download_url,
