$NetBSD: patch-setup.py,v 1.1 2015/08/22 16:20:34 thomasklausner Exp $

NetBSD has atimespec, like the other BSDs.
https://bitbucket.org/nikratio/python-llfuse/issues/48/netbsd-support-for-llfuse-041

--- setup.py.orig	2015-08-20 22:54:42.000000000 +0000
+++ setup.py
@@ -101,7 +101,7 @@ def main():
         link_args.append('-lrt')
         compile_args.append('-DHAVE_STRUCT_STAT_ST_ATIM')
 
-    elif os.uname()[0] in ('Darwin', 'FreeBSD'):
+    elif os.uname()[0] in ('Darwin', 'FreeBSD', 'NetBSD'):
         compile_args.append('-DHAVE_STRUCT_STAT_ST_ATIMESPEC')
     else:
         print("NOTE: unknown system (%s), nanosecond resolution file times "
