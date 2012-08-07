$NetBSD: patch-config.py,v 1.1 2012/08/07 19:43:37 fhajny Exp $

Use proper paths for storage and config example files.
--- setup.py.orig	2012-05-31 20:30:12.000000000 +0000
+++ setup.py
@@ -15,11 +15,11 @@ else:
 storage_dirs = []
 
 for subdir in ('whisper', 'rrd', 'log', 'log/webapp'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+  storage_dirs.append( ('@GRAPHITE_DIR@/%s' % subdir, []) )
 
 webapp_content = {}
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
 
@@ -29,8 +29,8 @@ for root, dirs, files in os.walk('webapp
     webapp_content[root].append(filepath)
 
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
-examples = [ ('examples', glob('examples/example-*')) ]
+conf_files = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('conf/*.example')) ]
+examples = [ ('@PREFIX@/@GRAPHITE_EGDIR@', glob('examples/example-*')) ]
 
 setup(
   name='graphite-web',
