$NetBSD$

Fix warningsabout int signedness mismatch.

--- xdalarm/xtmAlarmProc.c.orig	1997-05-04 22:02:19.000000000 +0000
+++ xdalarm/xtmAlarmProc.c
@@ -452,8 +452,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
