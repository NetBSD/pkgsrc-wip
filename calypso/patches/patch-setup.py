$NetBSD: patch-setup.py,v 1.1.1.1 2012/01/04 17:55:50 thomasklausner Exp $

Remove unused argument.

--- setup.py.orig	2012-01-04 17:30:02.000000000 +0000
+++ setup.py
@@ -67,8 +67,7 @@ setup(
     author="Keith Packard",
     author_email="keithp@keithp.com",
     url="http://keithp.com/",
-    download_url="http://keithp.com/git/calypso" % \
-        calypso.VERSION,
+    download_url="http://keithp.com/git/calypso",
     license="GNU GPL v3",
     platforms="Any",
     packages=["calypso", "calypso.acl"],
