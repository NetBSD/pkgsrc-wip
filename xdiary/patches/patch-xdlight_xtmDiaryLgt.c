$NetBSD$

--- xdlight/xtmDiaryLgt.c.orig	1997-05-04 23:13:08.000000000 +0000
+++ xdlight/xtmDiaryLgt.c
@@ -220,8 +220,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char **argv )
+int 
+  main( int argc, char **argv )
 {
 
   /* Variables. */
