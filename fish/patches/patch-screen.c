$NetBSD: patch-screen.c,v 1.1 2012/08/17 13:53:51 mwilhelmy Exp $

Fix compilation on NetBSD, where init_tabs is not suitable for assignment.

--- screen.c.orig	2009-03-08 14:46:47.000000000 +0000
+++ screen.c
@@ -16,6 +16,7 @@ efficient way for transforming that to t
 #include <sys/types.h>
 
 #ifdef HAVE_SYS_TERMIOS_H
+#include <termios.h>
 #include <sys/termios.h>
 #endif
 
@@ -92,13 +93,14 @@ static int try_sequence( char *seq, wcha
  */
 static int next_tab_stop( int in )
 {
+	int itabs = init_tabs;
 	/*
 	  Assume tab stops every 8 characters if undefined
 	*/
-	if( init_tabs <= 0 )
-		init_tabs = 8;
+	if( itabs <= 0 )
+		itabs = 8;
 				
-	return ( (in/init_tabs)+1 )*init_tabs;
+	return ( (in/itabs)+1 )*itabs;
 }
 
 /**
