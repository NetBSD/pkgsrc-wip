$NetBSD$

--- libpkg/pkg_jobs.c.orig	2025-02-17 16:47:31.543147819 +0000
+++ libpkg/pkg_jobs.c
@@ -2300,7 +2300,7 @@ pkg_jobs_fetch(struct pkg_jobs *j)
 	if (dlsize == 0)
 		return (EPKG_OK);
 
-#ifdef HAVE_FSTATFS
+#if defined(HAVE_FSTATFS) && !defined(__NetBSD__)
 	struct statfs fs;
 	while (statfs(cachedir, &fs) == -1) {
 		if (errno == ENOENT) {
