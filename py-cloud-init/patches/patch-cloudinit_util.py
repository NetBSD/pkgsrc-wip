$NetBSD$

--- cloudinit/util.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ cloudinit/util.py
@@ -74,7 +74,7 @@ from cloudinit.log.log_util import logexc
     version,
 )
 from cloudinit.log.log_util import logexc
-from cloudinit.settings import CFG_BUILTIN, PER_ONCE
+from cloudinit.settings import CFG_BUILTIN, PER_ONCE, CLOUD_CONFIG
 
 if TYPE_CHECKING:
     # Avoid circular import
@@ -2329,6 +2329,27 @@ def write_file(
             fh.flush()
     chmod(filename, mode)
 
+def write_cloud_config(
+    new_root,
+    content,
+    mode=0o644,
+):
+    """
+    Writes a cloud.cfg with the given content and sets the file mode
+    as specified.
+    The filename used is the system default location with new_root prepended.
+    Restores the SELinux context if possible.
+
+    @param new_root: The path to use instead of /.
+    @param content: The content to write to the file.
+    @param mode: The filesystem mode to set on the file.
+
+    """
+
+    rootless_config = os.path.splitroot(CLOUD_CONFIG)[2]
+    filename = os.path.join(new_root, rootless_config)
+    write_file(filename, content, mode=mode, ensure_dir_exists=True)
+    return filename
 
 def delete_dir_contents(dirname):
     """
