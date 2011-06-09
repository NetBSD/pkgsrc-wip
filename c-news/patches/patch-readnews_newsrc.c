$NetBSD: patch-readnews_newsrc.c,v 1.1 2011/06/09 19:49:50 hfath Exp $

Resolve conflict between stdio.h::getline() and our local one
by renaming.

--- readnews/newsrc.c.orig	1995-04-28 01:12:19.000000000 +0000
+++ readnews/newsrc.c
@@ -14,7 +14,7 @@ static int rclineno;		/* current lineno 
 static bool sortrc;		/* if we should sort on output */
 
 static newsrc *findnewsrc();
-static int getline();
+static int cnews_getline();
 static int dooptions();
 static int dorcline();
 static int writengline();
@@ -33,7 +33,7 @@ readnewsrc()
 		return;
 
 	rclineno = 0;
-	while (getline(f, word, rest))
+	while (cnews_getline(f, word, rest))
 		if (CMP(word, option) == 0)
 			dooptions(rest);
 		else
@@ -47,7 +47,7 @@ readnewsrc()
  * This is a poor design, as w & r are unchecked for overrun.
  */
 static int
-getline(f, w, r)
+cnews_getline(f, w, r)
 register FILE *f;
 char *w, *r;
 {
