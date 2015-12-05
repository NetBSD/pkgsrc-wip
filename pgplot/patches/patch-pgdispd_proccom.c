$NetBSD: patch-pgdispd_proccom.c,v 1.1 2013/12/12 19:10:29 slitvinov Exp $

Compiler was complaining about an extra definition

--- pgdispd/proccom.c.orig	1994-08-22 20:33:35.000000000 +0000
+++ pgdispd/proccom.c
@@ -93,10 +93,6 @@ static char rcsid[]="@(#)$Id: proccom.c,
 #include <sys/types.h>
 #include <netinet/in.h>
 
-#ifndef VMS
-#include <values.h>
-#endif
-
 #ifdef sun
 #include <memory.h>
 #endif
@@ -163,7 +159,6 @@ int *retbuflen;	/* the length of retbuf 
 	void drawline();	/* draw a line in the bitmap window */
 	Pixmap XCreatePixmap();
 
-	char *malloc();
 
 	if (!len & savedshorts)
 	{ /* an incomplete command was sent! */
