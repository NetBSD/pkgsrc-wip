$NetBSD: patch-dns.c,v 1.1 2015/03/11 14:37:02 makoto Exp $

Returning nothing

--- dns.c.orig	2015-03-11 23:30:10.000000000 +0900
+++ dns.c	2015-03-11 23:29:27.000000000 +0900
@@ -2222,6 +2222,7 @@ long opt;	/* option described in map fil
 	return 0;
 }
 
+void
 show_query(t, b, e)
 u_char *t, *b, *e;
 {
