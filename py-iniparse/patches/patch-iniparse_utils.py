$NetBSD$

--- iniparse/utils.py.orig	2010-05-08 19:36:42.000000000 +0000
+++ iniparse/utils.py
@@ -1,5 +1,5 @@
-import compat
-from ini import LineContainer, EmptyLine
+from . import compat
+from .ini import LineContainer, EmptyLine
 
 def tidy(cfg):
     """Clean up blank lines.
