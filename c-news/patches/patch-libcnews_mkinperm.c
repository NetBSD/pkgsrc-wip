$NetBSD: patch-libcnews_mkinperm.c,v 1.1 2011/08/17 19:56:09 hfath Exp $

As of NetBSD 6, time_t is an int64_t. Since we are only interested in
creating a unique filename, a cast to long is the easiest way out.

--- libcnews/mkinperm.c.orig	1994-11-28 01:15:29.000000000 +0000
+++ libcnews/mkinperm.c
@@ -44,7 +44,7 @@ char *class;		/* suffix for filename, de
 
 	now = time((time_t *)NULL);
 	for (ntries = 0; ; ntries++) {
-		(void) sprintf(p, "%s%ld%c%s", grade, now, uniq, class);
+		(void) sprintf(p, "%s%ld%c%s", grade, (long)now, uniq, class);
 		if (mkinpdebug)
 			(void) fprintf(stderr, "trying renaming to %s\n", name);
 		if (link(tmpname, name) >= 0)
