--- src/py/run_support.py.orig	2015-10-28 12:31:41.000000000 -0500
+++ src/py/run_support.py	2015-10-28 12:32:00.000000000 -0500
@@ -33,6 +33,7 @@
         content = ifs.read()
     content = _prepend_env_paths(content, names)
     with open(fn, 'w') as ofs:
+        ofs.write('#!/usr/bin/env bash\n\n')
         ofs.write(content)
 
 def use_tmpdir_for_files(basenames, src_dir, link_dir):
