$NetBSD: patch-libpkg_fetch.c,v 1.1 2015/02/15 23:32:45 khorben Exp $

--- libpkg/fetch.c.orig	2015-02-13 19:35:03.000000000 +0000
+++ libpkg/fetch.c
@@ -418,8 +418,13 @@ start_ssh(struct pkg_repo *repo, struct 
 			return (EPKG_FATAL);
 		}
 	}
+#if defined(__NetBSD__)
+	pkg_debug(1, "SSH> get %s %" PRIdMAX "", u->doc, (intmax_t)u->last_modified);
+	fprintf(repo->ssh, "get %s %" PRIdMAX "\n", u->doc, (intmax_t)u->last_modified);
+#else
 	pkg_debug(1, "SSH> get %s %" PRIdMAX "", u->doc, (intmax_t)u->ims_time);
 	fprintf(repo->ssh, "get %s %" PRIdMAX "\n", u->doc, (intmax_t)u->ims_time);
+#endif
 	if ((linelen = getline(&line, &linecap, repo->ssh)) > 0) {
 		if (line[linelen -1 ] == '\n')
 			line[linelen -1 ] = '\0';
