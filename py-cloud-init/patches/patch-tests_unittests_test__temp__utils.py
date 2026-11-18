$NetBSD$

--- tests/unittests/test_temp_utils.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/unittests/test_temp_utils.py
@@ -76,7 +76,8 @@ class TestTempUtils:
             mkdtemp,
         )
         assert "/fake/return/path" == retval
-        assert [{"dir": "/run/cloud-init/tmp"}] == calls
+        assert calls[0]["dir"].endswith("/run/cloud-init/tmp")
+        #assert [{"dir": "/run/cloud-init/tmp"}] == calls
 
     def test_mkstemp_default_non_root(self):
         """mkstemp creates secure tempfile under /tmp for the unprivileged."""
@@ -118,7 +119,9 @@ class TestTempUtils:
             mkstemp,
         )
         assert "/fake/return/path" == retval
-        assert [{"dir": "/run/cloud-init/tmp"}] == calls
+        # BSD has /var/run/... while Linux has /run/...
+        assert calls[0]["dir"].endswith("/run/cloud-init/tmp")
+        #assert [{"dir": "/run/cloud-init/tmp"}] == calls
 
     def test_tempdir_error_suppression(self):
         """test tempdir suppresses errors during directory removal."""
