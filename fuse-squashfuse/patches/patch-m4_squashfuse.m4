$NetBSD$

Fix shell portability.

--- m4/squashfuse.m4.orig	2016-03-28 03:11:58.000000000 +0000
+++ m4/squashfuse.m4
@@ -36,7 +36,7 @@ END
 		[sq_cv_prog_make_export=yes])
 	rm -f confmak
 ])
-AM_CONDITIONAL([MAKE_EXPORT],[test "x$sq_cv_prog_make_export" == xyes])
+AM_CONDITIONAL([MAKE_EXPORT],[test "x$sq_cv_prog_make_export" = xyes])
 ])
 
 
