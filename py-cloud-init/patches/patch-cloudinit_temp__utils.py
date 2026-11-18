$NetBSD$

--- cloudinit/temp_utils.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ cloudinit/temp_utils.py
@@ -21,7 +21,7 @@ def get_tmp_ancestor(odir=None, needs_exe: bool = Fals
         return _EXE_ROOT_TMPDIR
     if os.getuid() == 0:
         if util.is_BSD():
-            return "/var/" + _ROOT_TMPDIR
+            return "/var" + _ROOT_TMPDIR
         else:
             return _ROOT_TMPDIR
     return os.environ.get("TMPDIR", "/tmp")
