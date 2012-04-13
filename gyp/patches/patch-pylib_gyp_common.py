$NetBSD: patch-pylib_gyp_common.py,v 1.1 2012/04/13 22:38:16 ryo-on Exp $

--- pylib/gyp/common.py.orig	2012-04-13 19:31:34.000000000 +0000
+++ pylib/gyp/common.py
@@ -355,6 +355,9 @@ def GetFlavor(params):
     'sunos5': 'solaris',
     'freebsd7': 'freebsd',
     'freebsd8': 'freebsd',
+    'freebsd9': 'freebsd',
+    'netbsd5': 'netbsd',
+    'netbsd6': 'netbsd',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)
