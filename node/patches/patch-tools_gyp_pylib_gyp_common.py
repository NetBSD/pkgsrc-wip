$NetBSD: patch-tools_gyp_pylib_gyp_common.py,v 1.1 2013/03/03 12:38:37 jgoamakf Exp $

detects NetBSD.

--- tools/gyp/pylib/gyp/common.py.orig	2013-03-01 16:04:07.000000000 +0900
+++ tools/gyp/pylib/gyp/common.py	2013-03-01 16:04:24.000000000 +0900
@@ -371,6 +371,8 @@
     return 'solaris'
   if sys.platform.startswith('freebsd'):
     return 'freebsd'
+  if sys.platform.startswith('netbsd'):
+    return 'netbsd'
 
   return 'linux'
 
