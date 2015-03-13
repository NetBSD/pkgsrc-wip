$NetBSD: patch-main.c,v 1.1 2015/03/13 22:08:53 krytarowski Exp $

Include limits.h for INT_{MIN,MAX}

--- main.c.orig	2011-01-02 22:57:56.000000000 +0000
+++ main.c
@@ -15,6 +15,7 @@
 #endif	/* NO_MACRO */
 
 #include <err.h>
+#include <limits.h>
 
 int		 thisflag;			/* flags, this command	*/
 int		 lastflag;			/* flags, last command	*/
