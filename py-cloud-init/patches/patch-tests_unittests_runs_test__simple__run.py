$NetBSD$

--- tests/unittests/runs/test_simple_run.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/unittests/runs/test_simple_run.py
@@ -7,7 +7,7 @@ from cloudinit.config.modules import Modules
 
 from cloudinit import atomic_helper, safeyaml, stages, util
 from cloudinit.config.modules import Modules
-from cloudinit.settings import PER_INSTANCE
+from cloudinit.settings import PER_INSTANCE, CLOUD_CONFIG
 from cloudinit.sources import NetworkConfigSource
 from tests.unittests.helpers import replicate_test_root
 
@@ -41,10 +41,7 @@ def cfg(mocker, tmp_path):
         "cloud_init_modules": ["write_files", "spacewalk", "runcmd"],
     }
     cloud_cfg = safeyaml.dumps(_cfg)
-    util.ensure_dir(os.path.join(new_root, "etc", "cloud"))
-    util.write_file(
-        os.path.join(new_root, "etc", "cloud", "cloud.cfg"), cloud_cfg
-    )
+    util.write_cloud_config(new_root, cloud_cfg)
     return _cfg
 
 
@@ -172,8 +169,7 @@ class TestSimpleRun:
         cfg = copy.deepcopy(cfg)
         cfg["unverified_modules"] = ["spacewalk"]  # Would have skipped
         cloud_cfg = safeyaml.dumps(cfg)
-        util.ensure_dir(os.path.join("/etc", "cloud"))
-        util.write_file(os.path.join("/etc", "cloud", "cloud.cfg"), cloud_cfg)
+        util.write_file(CLOUD_CONFIG, cloud_cfg, ensure_dir_exists=True)
 
         initer = stages.Init()
         initer.read_cfg()
@@ -202,8 +198,7 @@ class TestSimpleRun:
         # Represent empty configuration in /etc/cloud/cloud.cfg
         cfg["cloud_init_modules"] = None
         cloud_cfg = safeyaml.dumps(cfg)
-        util.ensure_dir(os.path.join("/etc", "cloud"))
-        util.write_file(os.path.join("/etc", "cloud", "cloud.cfg"), cloud_cfg)
+        util.write_file(CLOUD_CONFIG, cloud_cfg, ensure_dir_exists=True)
 
         initer = stages.Init()
         initer.read_cfg()
