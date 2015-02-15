$NetBSD: patch-libpkg_pkgdb.c,v 1.1 2015/02/15 18:40:36 khorben Exp $

--- libpkg/pkgdb.c.orig	2015-02-13 19:35:03.000000000 +0000
+++ libpkg/pkgdb.c
@@ -34,6 +34,11 @@
 
 #include <sys/param.h>
 #include <sys/mount.h>
+#ifdef HAVE_SYS_STATFS_H
+#include <sys/statfs.h>
+#elif defined(HAVE_SYS_STATVFS_H)
+#include <sys/statvfs.h>
+#endif
 
 #include <assert.h>
 #include <errno.h>
@@ -886,7 +891,6 @@ int
 pkgdb_open_all(struct pkgdb **db_p, pkgdb_t type, const char *reponame)
 {
 	struct pkgdb	*db = NULL;
-	struct statfs	 stfs;
 	bool		 reopen = false;
 	bool		 profile = false;
 	char		 localpath[MAXPATHLEN];
@@ -945,10 +949,21 @@ pkgdb_open_all(struct pkgdb **db_p, pkgd
 		/*
 		 * Fall back on unix-dotfile locking strategy if on a network filesystem
 		 */
+#if defined(HAVE_SYS_STATVFS_H) && defined(ST_LOCAL)
+		struct statvfs stfs;
+
+		if (statvfs(dbdir, &stfs) == 0) {
+			if ((stfs.f_flag & ST_LOCAL) != ST_LOCAL)
+				sqlite3_vfs_register(sqlite3_vfs_find("unix-dotfile"), 1);
+		}
+#elif defined(HAVE_STATFS) && defined(MNT_LOCAL)
+		struct statfs stfs;
+
 		if (statfs(dbdir, &stfs) == 0) {
 			if ((stfs.f_flags & MNT_LOCAL) != MNT_LOCAL)
 				sqlite3_vfs_register(sqlite3_vfs_find("unix-dotfile"), 1);
 		}
+#endif
 
 		if (sqlite3_open(localpath, &db->sqlite) != SQLITE_OK) {
 			ERROR_SQLITE(db->sqlite, "sqlite open");
