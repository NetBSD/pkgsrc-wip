$NetBSD: patch-src_fr-command-lrzip.c,v 1.3 2015/04/09 03:12:51 krytarowski Exp $

* use portable member name

--- src/fr-command-lrzip.c.orig	2013-06-29 20:16:25.000000000 +0000
+++ src/fr-command-lrzip.c
@@ -53,7 +53,7 @@ list__process_line (char     *line,
 	struct stat st;
 	
 	if (stat (comm->filename, &st) == 0)
-		fdata->modified = st.st_mtim.tv_sec;
+		fdata->modified = st.st_mtime;
 	else
 		time(&(fdata->modified));
 
