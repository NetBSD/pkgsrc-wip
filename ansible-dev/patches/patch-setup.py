$NetBSD: patch-setup.py,v 1.1 2013/02/06 11:19:37 noud4 Exp $

Making sure setup.py does not pickup .orig files from the library when installing.

--- setup.py.orig	2013-01-26 16:36:42.000000000 +0000
+++ setup.py
@@ -8,9 +8,15 @@ sys.path.insert(0, os.path.abspath('lib'
 from ansible import __version__, __author__
 from distutils.core import setup
 
-# find library modules
+# find library modules, eliminating .orig leftovers
 from ansible.constants import DIST_MODULE_PATH
 data_files = [ (DIST_MODULE_PATH, glob('./library/*')) ]
+flist = glob('./library/*')
+data_filelist = []
+for file in flist:
+      if file.endswith('.orig'): continue
+      data_filelist.append(file)
+data_files = [ (DIST_MODULE_PATH, data_filelist ) ]
 
 print "DATA FILES=%s" % data_files
 
