$NetBSD: patch-lib_bup_metadata.py,v 1.1 2013/11/06 08:34:28 thomasklausner Exp $

Add patch from upstream to fix hardlinks test case.

--- lib/bup/metadata.py.orig	2013-11-06 07:25:56.000000000 +0000
+++ lib/bup/metadata.py
@@ -224,7 +224,6 @@ class Metadata:
         return self.uid == other.uid \
             and self.gid == other.gid \
             and self.rdev == other.rdev \
-            and self.atime == other.atime \
             and self.mtime == other.mtime \
             and self.ctime == other.ctime \
             and self.user == other.user \
