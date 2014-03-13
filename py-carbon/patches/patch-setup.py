$NetBSD: patch-setup.py,v 1.2 2014/03/13 20:47:13 fhajny Exp $

Use proper paths for storage and config example files.
--- setup.py.orig	2013-08-21 16:52:35.000000000 +0000
+++ setup.py
@@ -13,9 +13,9 @@ else:
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('@GRAPHITE_DIR@/whisper',[]), ('@GRAPHITE_DIR@/lists',[]),
+                 ('@GRAPHITE_DIR@/log',[]), ('@GRAPHITE_DIR@/rrd',[]) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
