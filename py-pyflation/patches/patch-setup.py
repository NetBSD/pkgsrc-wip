$NetBSD: patch-setup.py,v 1.1.1.1 2012/07/02 10:37:53 jihbed Exp $

--- setup.py.orig	2012-05-03 11:33:55.000000000 +0100
+++ setup.py	2012-05-15 14:49:13.000000000 +0100
@@ -8,6 +8,7 @@
 #For license and copyright information see LICENSE.txt which was distributed with this file.
 
 
+import sys
 
 from distutils.core import setup
 from distutils.extension import Extension
@@ -52,13 +53,13 @@
                   url='http://pyflation.ianhuston.net',
                   packages=['pyflation', 'pyflation.sourceterm',
                             'pyflation.analysis'],
-                  scripts=['bin/pyflation_firstorder.py', 
-                           'bin/pyflation_source.py', 
-                           'bin/pyflation_secondorder.py', 
-                           'bin/pyflation_combine.py',
-                           'bin/pyflation_srcmerge.py', 
-                           'bin/pyflation_qsubstart.py',
-                           'bin/pyflation_newrun.py'],
+                  scripts=['bin/pyflation_firstorder.py'+sys.version[0:3], 
+                           'bin/pyflation_source.py'+sys.version[0:3], 
+                           'bin/pyflation_secondorder.py'+sys.version[0:3], 
+                           'bin/pyflation_combine.py'+sys.version[0:3],
+                           'bin/pyflation_srcmerge.py'+sys.version[0:3], 
+                           'bin/pyflation_qsubstart.py'+sys.version[0:3],
+                           'bin/pyflation_newrun.py'+sys.version[0:3]],
                   package_data={'pyflation': ['qsub-sh.template', 
                                               'run_config.template']},
                   cmdclass = cmdclass,
