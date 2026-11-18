$NetBSD$

--- tests/unittests/cmd/devel/test_logs.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/unittests/cmd/devel/test_logs.py
@@ -179,7 +179,7 @@ class TestCollectLogs:
 
         for to_write in to_collect:
             write_file(
-                tmp_path / to_write, pathlib.Path(to_write).name, mode=0x700
+                tmp_path / to_write, pathlib.Path(to_write).name, mode=0o400
             )
 
         collect_dir = tmp_path / "collect"
@@ -225,7 +225,7 @@ class TestCollectLogs:
 
         for to_write in to_collect:
             write_file(
-                tmp_path / to_write, pathlib.Path(to_write).name, mode=0x700
+                tmp_path / to_write, pathlib.Path(to_write).name, mode=0o700
             )
 
         collect_dir = tmp_path / "collect"
