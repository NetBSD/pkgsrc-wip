$NetBSD: patch-lib_bup___helpers.c,v 1.1 2014/06/01 12:30:59 lexort Exp $

Work around broken utimensat in NetBSD 6.
Should be applied upstream.

--- lib/bup/_helpers.c.orig	2014-06-01 12:17:01.000000000 +0000
+++ lib/bup/_helpers.c
@@ -39,6 +39,14 @@
 #define BUP_HAVE_FILE_ATTRS 1
 #endif
 
+/*
+ * Check for defective UTIMENSAT support (NetBSD 6), and if so,
+ * pretend we don't have it.
+ */
+#if !defined(AT_FDCWD) || !defined(AT_SYMLINK_NOFOLLOW)
+#undef HAVE_UTIMENSAT
+#endif
+
 #ifndef FS_NOCOW_FL
 // Of course, this assumes it's a bitfield value.
 #define FS_NOCOW_FL 0
