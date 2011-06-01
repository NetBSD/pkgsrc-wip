$NetBSD: patch-bravo-config.py,v 1.1.1.1 2011/06/01 03:51:46 schnoebe Exp $

edit in the macro for configuration directory replacement.

--- bravo/config.py.orig	2011-05-08 16:36:35.000000000 +0000
+++ bravo/config.py
@@ -61,7 +61,7 @@ configuration = BravoConfigParser()
 
 def read_configuration():
     default_files = [
-        "/etc/bravo/bravo.ini",
+        "@PKG_SYSCONFDIR@/bravo.ini",
         expanduser("~/.bravo/bravo.ini"),
         expandvars("%APPDATA%/bravo/bravo.ini"),
         "bravo.ini",
