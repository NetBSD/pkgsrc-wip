$NetBSD$

Fix warningsabout int signedness mismatch.

--- xdaclunix/xtmAclUnix.c.orig	1997-05-04 22:02:19.000000000 +0000
+++ xdaclunix/xtmAclUnix.c
@@ -226,8 +226,8 @@ static void 
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
