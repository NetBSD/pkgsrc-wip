$NetBSD: patch-compat_bsd__compat.h,v 1.1 2015/02/23 18:24:20 khorben Exp $

Avoid discrepancy about the return type of readlinkat(2)

--- compat/bsd_compat.h.orig	2015-02-20 00:10:44.000000000 +0000
+++ compat/bsd_compat.h
@@ -103,8 +103,8 @@ int fstatat(int fd, const char *path, st
 int openat(int fd, const char *path, int flags, ...);
 #endif
 
-#if !HAVE_READLINKAT
-ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf, size_t bufsize);
+#if !HAVE_DECL_READLINKAT
+int readlinkat(int fd, const char *restrict path, char *restrict buf, size_t bufsize);
 #endif
 
 #if !HAVE_UNLINKAT
