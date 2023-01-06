$NetBSD$

Fix warningsabout int signedness mismatch.

--- xdremind/xtmRemMain.c.orig	1997-05-04 22:02:15.000000000 +0000
+++ xdremind/xtmRemMain.c
@@ -177,8 +177,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
