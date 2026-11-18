$NetBSD$

--- tests/unittests/cmd/test_main.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/unittests/cmd/test_main.py
@@ -11,7 +11,7 @@ from cloudinit.cmd import main
 
 from cloudinit import features, safeyaml, util
 from cloudinit.cmd import main
-from cloudinit.util import ensure_dir, load_text_file, write_file
+from cloudinit.util import ensure_dir, load_text_file, write_file, write_cloud_config
 
 MyArgs = namedtuple(
     "MyArgs", "debug files force local reporter subcommand skip_log_setup"
@@ -63,9 +63,7 @@ class TestMain:
         cloud_dir = os.path.join(tmpdir, "var/lib/cloud/")
         log_dir = os.path.join(tmpdir, "var/log/")
         ensure_dir(cloud_dir)
-        ensure_dir(os.path.join(tmpdir, "etc/cloud"))
         ensure_dir(log_dir)
-        cloud_cfg_file = os.path.join(tmpdir, "etc/cloud/cloud.cfg")
 
         cfg = {
             "datasource_list": ["None"],
@@ -88,7 +86,7 @@ class TestMain:
             ],
             "cloud_init_modules": ["write_files", "runcmd"],
         }
-        write_file(cloud_cfg_file, safeyaml.dumps(cfg))
+        cloud_cfg_file = write_cloud_config(tmpdir, safeyaml.dumps(cfg))
         yield copy.deepcopy(cfg), cloud_cfg_file
 
     @pytest.mark.parametrize(
