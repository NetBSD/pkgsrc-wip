$NetBSD: patch-tools_scons_scons-local-1.2.0_SCons_Tool_sunar.py,v 1.1 2011/06/25 12:46:03 genolopolis Exp $

--- tools/scons/scons-local-1.2.0/SCons/Tool/sunar.py.orig	2011-04-23 00:06:25.000000000 +0000
+++ tools/scons/scons-local-1.2.0/SCons/Tool/sunar.py
@@ -42,7 +42,7 @@ def generate(env):
     """Add Builders and construction variables for ar to an Environment."""
     SCons.Tool.createStaticLibBuilder(env)
     
-    if env.Detect('CC'):
+    if env.Detect('CC') and env['CC'] != 'gcc':
         env['AR']          = 'CC'
         env['ARFLAGS']     = SCons.Util.CLVar('-xar')
         env['ARCOM']       = '$AR $ARFLAGS -o $TARGET $SOURCES'
