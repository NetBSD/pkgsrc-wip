$NetBSD: patch-nnrpd_article.c,v 1.1 2011/09/21 20:10:17 hfath Exp $

memrchr(3) has been added as a library function in NetBSD 5.99.11
While here, fix printf format strings

--- nnrpd/article.c.orig	1997-12-12 17:54:08.000000000 +0000
+++ nnrpd/article.c
@@ -791,6 +791,7 @@ OVERGetHeader(p, field)
 
 #ifdef OVERSCREAM
 
+#if !defined(__NetBSD__) || __NetBSD_Version__ < 599001100
 /*
  * helper function, search backwards in memory
  */
@@ -806,6 +807,7 @@ memrchr(p, c, l)
 	    return(p);
     return(NULL);
 }
+#endif /* NetBSD */
 
 /*
  * mmap an OVERVIEW file.
@@ -1141,7 +1143,7 @@ OVERfind(artnum)
 	if ( topnr <= bottomnr ) {
 	    /* Safety net. This REALLY should never happen. */
 	    syslog(L_NOTICE,
-		   "%s: ASSERTION FAILED: %d < %d looking for %d in %s",
+		   "%s: ASSERTION FAILED: %lu < %lu looking for %lu in %s",
 		   ClientHost, topnr, bottomnr, artnum, GRPlast);
 	}
 	pos = bottom + (int) ((double) (top - bottom) * (MIDSKEW * 0.5) +
