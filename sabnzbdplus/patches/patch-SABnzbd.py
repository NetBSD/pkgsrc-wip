$NetBSD: patch-SABnzbd.py,v 1.1 2013/10/01 20:25:20 wongk Exp $

Fix absolute paths.

--- SABnzbd.py.orig	2013-09-02 20:06:57.000000000 +0000
+++ SABnzbd.py
@@ -41,6 +41,9 @@ except:
     print "The Python module Cheetah is required"
     sys.exit(1)
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,'%%PREFIX%%/share/sabnzbdplus')
 import cherrypy
 if not cherrypy.__version__.startswith("3.2"):
     print "Sorry, requires Python module Cherrypy 3.2 (use the included version)"
@@ -1010,7 +1013,7 @@ def main():
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = '%%PREFIX%%/share/sabnzbdplus'
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
