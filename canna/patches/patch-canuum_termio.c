--- canuum/termio.c.orig	2003-12-28 02:15:21.000000000 +0900
+++ canuum/termio.c	2012-08-12 17:49:02.000000000 +0900
@@ -175,7 +175,6 @@
 void
 closeTermData ()
 {
-  resetterm ();
   reset_shell_mode ();
 }
 
