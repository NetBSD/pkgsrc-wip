$NetBSD: patch-compat_file__at.c,v 1.1 2015/02/23 18:24:21 khorben Exp $

Avoid discrepancy about the return type of readlinkat(2)

--- compat/file_at.c.orig	2015-02-20 00:10:44.000000000 +0000
+++ compat/file_at.c
@@ -104,12 +104,12 @@ faccessat(int fd, const char *path, int 
 }
 #endif
 
-#if !HAVE_READLINKAT
-ssize_t
+#if !HAVE_DECL_READLINKAT
+int
 readlinkat(int fd, const char *restrict path, char *restrict buf,
 	   size_t bufsize)
 {
-	int ret;
+	ssize_t ret;
 
 	if ((ret = file_chdir_lock(fd) != 0))
 		return ret;
