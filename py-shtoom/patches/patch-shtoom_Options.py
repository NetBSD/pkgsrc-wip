$NetBSD: patch-shtoom_Options.py,v 1.1 2012/06/17 12:56:23 spzeidler Exp $

--- shtoom/Options.py.orig	2004-02-23 11:21:45.000000000 +0000
+++ shtoom/Options.py
@@ -263,7 +263,7 @@ class AllOptions(object):
             return None
         ini = self.emitConfigParser()
         if ini:
-            fp = open(self._filename, 'wU')
+            fp = open(self._filename, 'w')
             fp.write(ini)
             fp.close()
 
