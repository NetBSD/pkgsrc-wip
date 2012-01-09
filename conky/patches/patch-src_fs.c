$NetBSD: patch-src_fs.c,v 1.1.1.1 2012/01/09 17:47:49 thomasklausner Exp $

Use statvfs interface on NetBSD.

--- src/fs.c.orig	2010-10-05 21:29:36.000000000 +0000
+++ src/fs.c
@@ -44,6 +44,12 @@
 #include <sys/statfs.h>
 #endif
 
+/* NetBSD, Solaris */
+#ifdef HAVE_SYS_STATVFS_H
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
+
 /* freebsd && netbsd */
 #ifdef HAVE_SYS_PARAM_H
 #include <sys/param.h>
@@ -52,7 +58,7 @@
 #include <sys/mount.h>
 #endif
 
-#if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined (__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <mntent.h>
 #endif
 
@@ -138,7 +144,7 @@ static void update_fs_stat(struct fs_sta
 void get_fs_type(const char *path, char *result)
 {
 
-#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) || defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
 
 	struct statfs s;
 	if (statfs(path, &s) == 0) {
