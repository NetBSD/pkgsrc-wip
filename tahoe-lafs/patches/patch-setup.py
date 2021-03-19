$NetBSD$

--- setup.py.orig	2021-02-02 19:56:32.000000000 +0000
+++ setup.py
@@ -110,7 +110,7 @@ install_requires = [
     "six >= 1.10.0",
 
     # for 'tahoe invite' and 'tahoe join'
-    "magic-wormhole >= 0.10.2",
+#    "magic-wormhole >= 0.10.2",
 
     # Eliot is contemplating dropping Python 2 support.  Stick to a version we
     # know works on Python 2.7.
