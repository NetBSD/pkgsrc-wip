$NetBSD: patch-whitelist.c,v 1.1 2013/11/15 19:44:29 asau Exp $

--- whitelist.c.orig	2012-09-15 16:45:08.000000000 +0000
+++ whitelist.c
@@ -37,7 +37,7 @@ find_domain(const gchar *s, int flags)
 		return (NULL);
 
 	if (flags & XT_WL_TOPLEVEL &&
-	    !isdigit(uri->host[strlen(uri->host) - 1]))
+	    !isdigit((int) uri->host[strlen(uri->host) - 1]))
 		p = tld_get_suffix(uri->host);
 	else
 		p = uri->host;
