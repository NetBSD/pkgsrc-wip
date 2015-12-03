$NetBSD$

--- setup.py.orig	2015-11-27 10:37:07.000000000 -0800
+++ setup.py	2015-12-03 10:56:59.000000000 -0800
@@ -13,15 +13,16 @@
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/whisper',[]), ('storage/lists',[]),
-                 ('storage/log',[]), ('storage/rrd',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('@GRAPHITE_DIR@/whisper',[]), ('@GRAPHITE_DIR@/lists',[]),
+                 ('@GRAPHITE_DIR@/log',[]), ('@GRAPHITE_DIR@/rrd',[]) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
 # Let's include redhat init scripts, despite build platform
 # but won't put them in /etc/init.d/ automatically anymore
-init_scripts = [ ('examples/init.d', ['distro/redhat/init.d/carbon-cache',
+init_scripts = [ ('@GRAPHITE_RCD@',
+                                     ['distro/redhat/init.d/carbon-cache',
                                       'distro/redhat/init.d/carbon-relay',
                                       'distro/redhat/init.d/carbon-aggregator']) ]
 install_files += init_scripts
