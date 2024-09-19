$NetBSD: patch-src_main.c,v 1.1 2013/04/29 20:46:19 khorben Exp $

Fixed immediate crash on startup (GLib (gthread-posix.c): Unexpected error from
C library during 'pthread_mutex_unlock': Operation not permitted.  Aborting.)

--- src/main.c.orig	2012-06-14 04:41:11.000000000 +0000
+++ src/main.c
@@ -199,9 +199,13 @@ main (int argc, char *argv[])
 #endif
 	
 	init();
+
+	gdk_threads_enter();
 	
 	gtk_main ();
 
+	gdk_threads_leave();
+
 
 	
 	return 0;
