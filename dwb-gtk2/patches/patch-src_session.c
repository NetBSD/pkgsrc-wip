$NetBSD: patch-src_session.c,v 1.1 2015/05/27 17:59:19 f8l Exp $

Imported from http://cvsweb.openbsd.org/cgi-bin/cvsweb/~checkout~/ports/www/dwb/patches/patch-src_session_c?rev=1.1

--- src/session.c.orig	2014-03-07 11:39:43.000000000 +0000
+++ src/session.c
@@ -37,7 +37,7 @@ session_get_groups() 
 {
     char **groups = NULL;
     char *content = util_get_file_content(dwb.files[FILES_SESSION], NULL);
-    if (content) 
+    if (content && strlen(content))
     {
         groups = g_regex_split_simple("^g:", content, G_REGEX_MULTILINE, G_REGEX_MATCH_NOTEMPTY);
         g_free(content);
