$NetBSD: patch-libpkg_pkg__jobs.c,v 1.1 2015/02/15 18:40:36 khorben Exp $

--- libpkg/pkg_jobs.c.orig	2015-02-13 19:35:03.000000000 +0000
+++ libpkg/pkg_jobs.c
@@ -32,6 +32,12 @@
 #include <sys/mount.h>
 #include <sys/types.h>
 
+#ifdef HAVE_SYS_STATFS_H
+#include <sys/statfs.h>
+#elif defined(HAVE_SYS_STATVFS_H)
+#include <sys/statvfs.h>
+#endif
+
 #include <archive.h>
 #include <archive_entry.h>
 #include <assert.h>
@@ -1995,9 +2001,8 @@ pkg_jobs_fetch(struct pkg_jobs *j)
 {
 	struct pkg *p = NULL;
 	struct pkg_solved *ps;
-	struct statfs fs;
 	struct stat st;
-	int64_t dlsize = 0;
+	int64_t dlsize = 0, fs_avail = -1;
 	const char *cachedir = NULL;
 	char cachedpath[MAXPATHLEN];
 	bool mirror = (j->flags & PKG_FLAG_FETCH_MIRROR) ? true : false;
@@ -2032,6 +2037,8 @@ pkg_jobs_fetch(struct pkg_jobs *j)
 	if (dlsize == 0)
 		return (EPKG_OK);
 
+#ifdef HAVE_STATFS
+	struct statfs fs;
 	while (statfs(cachedir, &fs) == -1) {
 		if (errno == ENOENT) {
 			if (mkdirs(cachedir) != EPKG_OK)
@@ -2041,14 +2048,27 @@ pkg_jobs_fetch(struct pkg_jobs *j)
 			return (EPKG_FATAL);
 		}
 	}
+	fs_avail = fs.f_bsize * (int64_t)fs.f_bavail;
+#elif defined(HAVE_SYS_STATVFS_H)
+	struct statvfs fs;
+	while (statvfs(cachedir, &fs) == -1) {
+		if (errno == ENOENT) {
+			if (mkdirs(cachedir) != EPKG_OK)
+				return (EPKG_FATAL);
+		} else {
+			pkg_emit_errno("statvfs", cachedir);
+			return (EPKG_FATAL);
+		}
+	}
+	fs_avail = fs.f_bsize * (int64_t)fs.f_bavail;
+#endif
 
-	if (dlsize > ((int64_t)fs.f_bsize * (int64_t)fs.f_bavail)) {
-		int64_t fsize = (int64_t)fs.f_bsize * (int64_t)fs.f_bavail;
+	if (fs_avail != -1 && dlsize > fs_avail) {
 		char dlsz[9], fsz[9];
 
 		humanize_number(dlsz, sizeof(dlsz), dlsize, "B",
 		    HN_AUTOSCALE, HN_IEC_PREFIXES);
-		humanize_number(fsz, sizeof(fsz), fsize, "B",
+		humanize_number(fsz, sizeof(fsz), fs_avail, "B",
 		    HN_AUTOSCALE, HN_IEC_PREFIXES);
 		pkg_emit_error("Not enough space in %s, needed %s available %s",
 		    cachedir, dlsz, fsz);
