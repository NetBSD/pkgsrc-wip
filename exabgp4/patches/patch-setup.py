$NetBSD$

In NetBSD, it is uncommon to write these files directly to /etc

--- setup.py.orig	2021-01-28 19:05:54.528803756 +0000
+++ setup.py
@@ -31,7 +31,7 @@ def filesOf(directory):
 
 
 data_files = [
-    ('etc/exabgp/examples', filesOf('etc/exabgp')),
+    ('share/examples/exabgp', filesOf('etc/exabgp')),
 ]
 
 if platform.system() != 'NetBSD':
