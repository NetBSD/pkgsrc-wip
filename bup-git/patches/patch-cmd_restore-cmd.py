$NetBSD: patch-cmd_restore-cmd.py,v 1.1 2013/11/06 08:34:28 thomasklausner Exp $

Add patch from upstream to fix hardlinks test case.

--- cmd/restore-cmd.py.orig	2013-11-06 07:25:56.000000000 +0000
+++ cmd/restore-cmd.py
@@ -79,7 +79,6 @@ def hardlink_compatible(target_path, tar
         return False
     target_node = top.lresolve(target_vfs_path)
     if src_node.mode != target_node.mode \
-            or src_node.atime != target_node.atime \
             or src_node.mtime != target_node.mtime \
             or src_node.ctime != target_node.ctime \
             or src_node.hash != target_node.hash:
