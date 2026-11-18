$NetBSD$

--- tests/unittests/runs/test_merge_run.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/unittests/runs/test_merge_run.py
@@ -41,10 +41,7 @@ def cfg(tmp_path, mocker):
         },
     }
     cloud_cfg = safeyaml.dumps(cfg)
-    util.ensure_dir(os.path.join(new_root, "etc", "cloud"))
-    util.write_file(
-        os.path.join(new_root, "etc", "cloud", "cloud.cfg"), cloud_cfg
-    )
+    util.write_cloud_config(new_root, cloud_cfg)
 
 
 @pytest.mark.usefixtures("fake_filesystem")
