$NetBSD: patch-tools_utils.py,v 1.1 2011/09/10 19:57:09 genolopolis Exp $

--- tools/utils.py.orig	2011-05-02 18:26:32.000000000 +0000
+++ tools/utils.py
@@ -59,6 +59,8 @@ def GuessOS():
     return 'freebsd'
   elif id == 'OpenBSD':
     return 'openbsd'
+  elif id == 'NetBSD':
+    return 'netbsd'
   elif id == 'SunOS':
     return 'solaris'
   else:
