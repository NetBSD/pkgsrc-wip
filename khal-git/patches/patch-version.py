$NetBSD: patch-version.py,v 1.1 2014/10/01 06:37:49 thomasklausner Exp $

Do not include git version in egg name.

--- version.py.orig	2014-10-01 06:33:50.000000000 +0000
+++ version.py
@@ -29,7 +29,7 @@ if not RELEASE:
 
         if revision != VERSION:
             revision = revision.lstrip(string.digits + '.')
-            VERSION += '.dev' + revision
+            VERSION += '.dev'
     except:
         VERSION += '.dev'
         warnings.warn("WARNING: git not installed or failed to run")
