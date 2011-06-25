$NetBSD: patch-tools_scons_scons-local-1.2.0_SCons_Tool_suncc.py,v 1.1 2011/06/25 12:46:03 genolopolis Exp $

Avoid Sun toolchain assumed if CC set to gcc.
--- tools/scons/scons-local-1.2.0/SCons/Tool/suncc.py.orig     2011-03-03 06:10:26.000000000 +0000
+++ tools/scons/scons-local-1.2.0/SCons/Tool/suncc.py
@@ -35,6 +35,7 @@ __revision__ = "src/engine/SCons/Tool/su
 import SCons.Util

 import cc
+import os

 def generate(env):
     """
@@ -49,4 +50,4 @@ def generate(env):
     env['SHOBJSUFFIX']  = '.o'

 def exists(env):
-    return env.Detect('CC')
+    return env.Detect('CC') and os.environ['CC'] != 'gcc'
