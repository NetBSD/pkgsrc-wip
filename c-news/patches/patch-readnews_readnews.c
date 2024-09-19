$NetBSD: patch-readnews_readnews.c,v 1.1 2011/08/17 19:56:09 hfath Exp $

time_t might be int64_t now, adapt.

--- readnews/readnews.c.orig	1995-04-28 01:12:21.000000000 +0000
+++ readnews/readnews.c
@@ -4,6 +4,7 @@
  *	Michael Rourke (UNSW) April 1984
  */
 
+#include <time.h>
 #include "defs.h"
 
 #define ARTSEP "/"
@@ -33,7 +34,7 @@ extern newsrc	*rc;		/* internal .newsrc 
 
 active *alist;		/* internal active list */
 
-long now;		/* current time */
+time_t now;		/* current time */
 bool interrupt;		/* if interrupt hit */
 char *newsdir;		/* %news */
 bool su;		/* if super user (not used) */
@@ -840,7 +841,7 @@ char *fname;
 	if (s == NULL)
 		return;
 	(void) strcpy(tmpf, "/tmp/rfXXXXXX");
-	(void) mktemp(tmpf);
+	(void) mkstemp(tmpf);
 	fo = fopen(tmpf, "w");
 	if (fo == NULL)
 		error("can't create `%s'", tmpf);
@@ -950,7 +951,7 @@ char *s;
 	register char *cp;
 	register FILE	*sf;
 	register char *aname;
-	long then;
+	time_t then;
 	extern char *getenv();
 
 	if (!*s) {
