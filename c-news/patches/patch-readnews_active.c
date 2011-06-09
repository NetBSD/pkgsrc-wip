$NetBSD: patch-readnews_active.c,v 1.1 2011/06/09 19:49:50 hfath Exp $

Resolve conflict between stdio.h::getline() and our local one
by renaming.

--- readnews/active.c.orig	1990-11-19 22:20:05.000000000 +0000
+++ readnews/active.c
@@ -12,7 +12,7 @@ static int lineno;
 static active	*alist;
 
 static
-getline(f, g, d, d2)
+cnews_getline(f, g, d, d2)
 register FILE *f;
 char *g, *d, *d2;
 {
@@ -61,7 +61,7 @@ readactive()
 	alist = last = NULL;
 	f = fopenf(ctlfile("active"), "r");
 	lineno = 0;
-	while (getline(f, gbuf, dbuf, dbuf2)) {
+	while (cnews_getline(f, gbuf, dbuf, dbuf2)) {
 		ap = NEW(active);
 		ap->a_name = newstr(gbuf);
 		ap->a_seq = atol(dbuf);
