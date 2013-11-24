$NetBSD: patch-cmd_index-cmd.py,v 1.1 2013/11/24 02:35:19 thomasklausner Exp $

Document --exclude-rx-from.

--- cmd/index-cmd.py.orig	2013-11-15 09:46:48.000000000 +0000
+++ cmd/index-cmd.py
@@ -196,7 +196,8 @@ fake-invalid mark all index entries as i
 f,indexfile=  the name of the index file (normally BUP_DIR/bupindex)
 exclude=   a path to exclude from the backup (can be used more than once)
 exclude-from= a file that contains exclude paths (can be used more than once)
-exclude-rx= skip paths that match the unanchored regular expression
+exclude-rx= skip paths that match the unanchored regular expression (can be used more than once)
+exclude-rx-from= a file that contains exclude patterns (can be used more than once)
 v,verbose  increase log output (can be used more than once)
 x,xdev,one-file-system  don't cross filesystem boundaries
 """
