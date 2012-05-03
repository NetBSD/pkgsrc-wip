$NetBSD: patch-pylib_gyp_common.py,v 1.2 2012/05/03 02:29:16 obache Exp $

--- pylib/gyp/common.py.orig	2012-05-03 02:20:39.000000000 +0000
+++ pylib/gyp/common.py
@@ -356,6 +356,8 @@ def GetFlavor(params):
     'freebsd7': 'freebsd',
     'freebsd8': 'freebsd',
     'freebsd9': 'freebsd',
+    'netbsd5': 'netbsd',
+    'netbsd6': 'netbsd',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)
