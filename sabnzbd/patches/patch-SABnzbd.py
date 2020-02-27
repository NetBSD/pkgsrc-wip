$NetBSD$

Fix path.

--- SABnzbd.py.orig	2020-02-12 20:18:12.258920844 +0000
+++ SABnzbd.py
@@ -42,6 +42,10 @@ import ssl
 import time
 import re
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'@PREFIX@/share/sabnzbd')
+
 try:
     import Cheetah
     if Cheetah.Version[0] < '2':
@@ -919,7 +923,8 @@ def main():
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    # sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = "@PREFIX@/share/sabnzbd"
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
