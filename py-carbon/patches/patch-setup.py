$NetBSD: patch-setup.py,v 1.1 2012/08/07 19:41:18 fhajny Exp $

Use proper paths for storage and config example files.
--- setup.py.orig	2012-05-31 20:32:28.000000000 +0000
+++ setup.py
@@ -12,9 +12,9 @@ else:
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('@GRAPHITE_DIR@/whisper',[]), ('@GRAPHITE_DIR@/lists',[]),
+                 ('@GRAPHITE_DIR@/log',[]), ('@GRAPHITE_DIR@/rrd',[]) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
 #XXX Need a way to have these work for bdist_rpm but be left alone for everything else
 #init_scripts = [ ('/etc/init.d', ['distro/redhat/init.d/carbon-cache',
 #                                  'distro/redhat/init.d/carbon-relay',
