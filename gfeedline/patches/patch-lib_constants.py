$NetBSD: patch-lib_constants.py,v 1.1 2013/12/21 15:14:09 noud4 Exp $

Use pkgsrc path.

--- lib/constants.py.orig	2013-12-18 22:02:12.000000000 +0000
+++ lib/constants.py
@@ -9,7 +9,7 @@ APP_NAME = 'gfeedline'
 
 SHARED_DATA_DIR = abspath(os.path.join(dirname(__file__), '../share'))
 if not os.access(os.path.join(SHARED_DATA_DIR, 'gfeedline.glade'), os.R_OK):
-    SHARED_DATA_DIR = '/usr/share/gfeedline'
+    SHARED_DATA_DIR = '@PREFIX@/share/gfeedline'
 
 # DATA_HOME = os.path.join(xdg_data_home, APP_NAME)
 CACHE_HOME = os.path.join(xdg_cache_home, APP_NAME)
