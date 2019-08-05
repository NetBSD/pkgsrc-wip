$NetBSD: patch-setup.py,v 1.1 2015/12/11 21:45:07 riz Exp $

Use proper paths for storage and config example files.

--- setup.py.orig	2019-08-05 16:53:51.886345867 +0000
+++ setup.py
@@ -59,17 +59,17 @@ else:
 storage_dirs = []
 
 for subdir in ('whisper/dummy.txt', 'ceres/dummy.txt', 'rrd/dummy.txt', 'log/dummy.txt', 'log/webapp/dummy.txt'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+  storage_dirs.append( ('@GRAPHITE_DIR@/%s' % subdir, []) )
 
 webapp_content = defaultdict(list)
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
     webapp_content[root].append(filepath)
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
-examples = [ ('examples', glob('examples/example-*')) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
+examples = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('examples/example-*')) ]
 
 try:
     setup(
