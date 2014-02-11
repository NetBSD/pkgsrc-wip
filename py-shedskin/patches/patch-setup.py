$NetBSD: patch-setup.py,v 1.1 2014/02/11 20:31:14 jihbed Exp $

--- setup.py.orig	2014-02-11 21:21:02.000000000 +0100
+++ setup.py	2014-02-11 21:22:14.000000000 +0100
@@ -1,6 +1,7 @@
 #!/usr/bin/env python
 
 from distutils.core import setup, Command
+import sys
 import os
 
 class run_tests(Command):
@@ -22,7 +23,7 @@
       version='0.9.4',
       description='Shed Skin is an experimental compiler, that can translate pure, but implicitly statically typed Python programs into optimized C++. It can generate stand-alone programs or extension modules that can be imported and used in larger Python programs.',
       url='http://code.google.com/p/shedskin/',
-      scripts=['scripts/shedskin'],
+      scripts=['scripts/shedskin'+ sys.version[0:3]],
       cmdclass={'test':run_tests},
       packages=['shedskin'],
       package_data={'shedskin': ['lib/*.cpp', 'lib/*.hpp', 'lib/builtin/*.cpp', 'lib/builtin/*.hpp', 'lib/*.py', 'lib/os/*.cpp', 'lib/os/*.hpp', 'lib/os/*.py', 'FLAGS*', 'illegal']},
