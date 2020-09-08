$NetBSD$

Fix path.

--- SABnzbd.py.orig	2020-08-30 20:58:31.000000000 +0200
+++ SABnzbd.py	2020-09-07 20:29:13.831328403 +0200
@@ -35,6 +35,10 @@
 import time
 import re
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'@PREFIX@/share/sabnzbd')
+
 try:
     import Cheetah
     import feedparser
@@ -925,7 +929,8 @@
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    # sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = "@PREFIX@/share/sabnzbd"
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
