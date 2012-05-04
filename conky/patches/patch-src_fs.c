$NetBSD: patch-src_fs.c,v 1.2 2012/05/04 10:57:24 imilh Exp $

Use statvfs interface on NetBSD.

--- src/fs.c.orig	2010-10-05 21:29:36.000000000 +0000
+++ src/fs.c
@@ -44,6 +44,13 @@
 #include <sys/statfs.h>
 #endif
 
+/* NetBSD, Solaris */
+/* #ifdef HAVE_SYS_STATVFS_H */
+#ifdef __NetBSD__ /* this this is ugly anyway... */
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
+
 /* freebsd && netbsd */
 #ifdef HAVE_SYS_PARAM_H
 #include <sys/param.h>
@@ -52,7 +59,7 @@
 #include <sys/mount.h>
 #endif
 
-#if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined (__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <mntent.h>
 #endif
 
@@ -138,7 +145,7 @@ static void update_fs_stat(struct fs_sta
 void get_fs_type(const char *path, char *result)
 {
 
-#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) || defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
 
 	struct statfs s;
 	if (statfs(path, &s) == 0) {
