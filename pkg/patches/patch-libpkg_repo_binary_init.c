$NetBSD: patch-libpkg_repo_binary_init.c,v 1.1 2015/02/15 18:40:36 khorben Exp $

--- libpkg/repo/binary/init.c.orig	2015-02-13 19:35:03.000000000 +0000
+++ libpkg/repo/binary/init.c
@@ -23,6 +23,11 @@
 
 #include <sys/param.h>
 #include <sys/mount.h>
+#ifdef HAVE_SYS_STATFS_H
+#include <sys/statfs.h>
+#elif defined(HAVE_SYS_STATVFS_H)
+#include <sys/statvfs.h>
+#endif
 
 #include <assert.h>
 #include <errno.h>
@@ -294,7 +299,6 @@ int
 pkg_repo_binary_open(struct pkg_repo *repo, unsigned mode)
 {
 	char filepath[MAXPATHLEN];
-	struct statfs stfs;
 	const char *dbdir = NULL;
 	sqlite3 *sqlite = NULL;
 	int flags;
@@ -308,10 +312,21 @@ pkg_repo_binary_open(struct pkg_repo *re
 	/*
 	 * Fall back on unix-dotfile locking strategy if on a network filesystem
 	 */
+#if defined(HAVE_SYS_STATVFS_H) && defined(ST_LOCAL)
+	struct statvfs stfs;
+
+	if (statvfs(dbdir, &stfs) == 0) {
+		if ((stfs.f_flag & ST_LOCAL) != ST_LOCAL)
+			sqlite3_vfs_register(sqlite3_vfs_find("unix-dotfile"), 1);
+	}
+#elif defined(HAVE_STATFS) && defined(MNT_LOCAL)
+	struct statfs stfs;
+
 	if (statfs(dbdir, &stfs) == 0) {
 		if ((stfs.f_flags & MNT_LOCAL) != MNT_LOCAL)
 			sqlite3_vfs_register(sqlite3_vfs_find("unix-dotfile"), 1);
 	}
+#endif
 
 	snprintf(filepath, sizeof(filepath), "%s/%s.meta",
 		dbdir, pkg_repo_name(repo));
@@ -399,7 +414,6 @@ int
 pkg_repo_binary_create(struct pkg_repo *repo)
 {
 	char filepath[MAXPATHLEN];
-	struct statfs stfs;
 	const char *dbdir = NULL;
 	sqlite3 *sqlite = NULL;
 	int retcode;
@@ -416,10 +430,21 @@ pkg_repo_binary_create(struct pkg_repo *
 	/*
 	 * Fall back on unix-dotfile locking strategy if on a network filesystem
 	 */
+#if defined(HAVE_SYS_STATVFS_H) && defined(ST_LOCAL)
+	struct statvfs stfs;
+
+	if (statvfs(dbdir, &stfs) == 0) {
+		if ((stfs.f_flag & ST_LOCAL) != ST_LOCAL)
+			sqlite3_vfs_register(sqlite3_vfs_find("unix-dotfile"), 1);
+	}
+#elif defined(HAVE_STATFS) && defined(MNT_LOCAL)
+	struct statfs stfs;
+
 	if (statfs(dbdir, &stfs) == 0) {
 		if ((stfs.f_flags & MNT_LOCAL) != MNT_LOCAL)
 			sqlite3_vfs_register(sqlite3_vfs_find("unix-dotfile"), 1);
 	}
+#endif
 
 	/* Open for read/write/create */
 	if (sqlite3_open(filepath, &sqlite) != SQLITE_OK)
