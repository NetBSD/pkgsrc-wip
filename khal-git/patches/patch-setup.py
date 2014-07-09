$NetBSD: patch-setup.py,v 1.1 2014/07/09 04:30:00 thomasklausner Exp $

Do not include git version in egg name.

--- setup.py.orig	2014-07-09 02:09:33.000000000 +0000
+++ setup.py
@@ -30,7 +30,7 @@ if not RELEASE:
 
         if revision != VERSION:
             revision = revision.lstrip(string.digits + '.')
-            VERSION += '.dev' + revision
+            VERSION += '.dev'
     except:
         VERSION += '.dev'
         warnings.warn("WARNING: git not installed or failed to run")
