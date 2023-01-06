$NetBSD$

Fix warningsabout int signedness mismatch.

--- xdnotify/xtmNotify.c.orig	1997-05-04 22:02:15.000000000 +0000
+++ xdnotify/xtmNotify.c
@@ -244,8 +244,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
