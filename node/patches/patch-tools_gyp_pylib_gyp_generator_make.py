$NetBSD: patch-tools_gyp_pylib_gyp_generator_make.py,v 1.2 2013/03/13 13:06:33 fhajny Exp $

Add support for NetBSD.

--- tools/gyp/pylib/gyp/generator/make.py.orig	2013-03-11 00:36:28.000000000 +0000
+++ tools/gyp/pylib/gyp/generator/make.py
@@ -2000,7 +2000,7 @@ def GenerateOutput(target_list, target_d
         'flock_index': 2,
         'extra_commands': SHARED_HEADER_SUN_COMMANDS,
     })
-  elif flavor == 'freebsd' or flavor == 'dragonflybsd':
+  elif flavor == 'freebsd' or flavor == 'dragonflybsd' or flavor == 'netbsd':
     header_params.update({
         'flock': 'lockf',
     })
