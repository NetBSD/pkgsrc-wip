$NetBSD: patch-setup.py,v 1.1 2012/12/31 23:38:01 othyro Exp $

Don't allow manpage to be installed to share/man.

--- setup.py.orig	2011-09-04 10:34:17.000000000 +0000
+++ setup.py
@@ -30,8 +30,6 @@ else: no_lang = 0
 data_files = [
   (os.path.join("songwrite2", "data"),
   [os.path.join("data", file) for file in os.listdir("data") if (file != "CVS") and (file != ".svn") and (file != ".arch-ids")]),
-  (os.path.join("man", "man1"),
-  [os.path.join("manpage", "man1", "songwrite2.1")]),
   ]
 if not no_lang:
   data_files = data_files + [
