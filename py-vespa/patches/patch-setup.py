$NetBSD$

--- setup.py.orig	2016-05-10 14:12:27.000000000 +0000
+++ setup.py
@@ -11,6 +11,7 @@ except ImportError:
     build_ext = None
     
 import os
+import sys
 
 def readme():
     with open('README.rst') as f:
@@ -60,11 +61,11 @@ setup(name = "VESPA",
                       'vespa.stars': ['data/*'],
                       'vespa.orbits':['data/*']},
       ext_modules = cythonize(transit_utils),
-      scripts = ['scripts/get_trilegal',
-                 'scripts/koifpp',
-                 'scripts/batch_koifpp_condor',
-                 'scripts/calcfpp',
-                 'scripts/koifpp-config'],
+      scripts = ['scripts/get_trilegal'+sys.version[0:3],
+                 'scripts/koifpp'+sys.version[0:3],
+                 'scripts/batch_koifpp_condor'+sys.version[0:3],
+                 'scripts/calcfpp'+sys.version[0:3],
+                 'scripts/koifpp-config'+sys.version[0:3]],
       cmdclass = {'build_ext': build_ext},
       classifiers=[
         'Development Status :: 4 - Beta',
