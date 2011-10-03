$NetBSD: patch-README.rst,v 1.1 2011/10/03 00:21:17 schnoebe Exp $

--- README.rst.orig	2011-06-16 16:12:26.000000000 +0000
+++ README.rst
@@ -172,7 +172,7 @@ Running
 Bravo includes a twistd plugin, so it's quite easy to run. Just copy
 bravo.ini.example to bravo.ini, and put it in one of these locations:
 
- * /etc/bravo/
+ * @PKG_SYSCONFDIR@/bravo/
  * ~/.bravo/
  * Your working directory
 
