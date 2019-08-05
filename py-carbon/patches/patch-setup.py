$NetBSD: patch-setup.py,v 1.1 2015/12/11 21:40:50 riz Exp $

Rearrange installation dirs for pkgsrc, and don't install redhat files

--- setup.py.orig	2019-08-05 15:57:03.615377427 +0000
+++ setup.py
@@ -58,21 +58,13 @@ else:
   setup_kwargs = dict()
 
 
-storage_dirs = [ ('storage/ceres/dummy.txt', []), ('storage/whisper/dummy.txt',[]),
-                 ('storage/lists',[]), ('storage/log/dummy.txt',[]),
-                 ('storage/rrd/dummy.txt',[]) ]
-conf_files = [ ('conf', glob('conf/*.example')) ]
+storage_dirs = [ ('@GRAPHITE_DIR@/ceres/dummy.txt', []), ('@GRAPHITE_DIR@/whisper/dummy.txt',[]),
+                 ('@GRAPHITE_DIR@/lists',[]), ('@GRAPHITE_DIR@/log/dummy.txt',[]),
+                 ('@GRAPHITE_DIR@/rrd/dummy.txt',[]) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
 
 install_files = storage_dirs + conf_files
 
-# Let's include redhat init scripts, despite build platform
-# but won't put them in /etc/init.d/ automatically anymore
-init_scripts = [ ('examples/init.d', ['distro/redhat/init.d/carbon-cache',
-                                      'distro/redhat/init.d/carbon-relay',
-                                      'distro/redhat/init.d/carbon-aggregator']) ]
-install_files += init_scripts
-
-
 try:
     setup(
         name='carbon',
