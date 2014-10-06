$NetBSD: patch-setup.py,v 1.1 2014/10/06 23:08:59 jihbed Exp $

--- setup.py.orig	2014-07-28 01:01:44.000000000 +0100
+++ setup.py	2014-07-28 01:02:45.000000000 +0100
@@ -1,6 +1,13 @@
 #!/usr/bin/env python
 # vim: ts=3:sw=3
 
+import os.path
+import os
+import fnmatch
+import fileinput
+import sys
+
+
 from distutils.core import setup
 from distutils.sysconfig import get_config_vars
 from distutils.command.build_py import build_py as _build_py
@@ -10,10 +17,7 @@
 from distutils.util import change_root as _change_root
 from distutils import log
 
-import os.path
-import os
-import fnmatch
-import fileinput
+
 
 VERSION = "2.0.0"
 SVN_REVISION = "$Rev:701$"
@@ -205,8 +209,8 @@
 			'golem': 'src/python/golem'
 		},
 		scripts=[
-			'src/python/golem/gosam-config.py',
-			'src/python/golem/gosam.py'
+			'src/python/golem/gosam-config.py'+sys.version[0:3],
+			'src/python/golem/gosam.py'+sys.version[0:3]
 		],
 		cmdclass={'build_py': build_py,
 			'install_scripts':install_scripts,
