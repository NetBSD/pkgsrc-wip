$NetBSD: patch-gcc_lto_lto.c,v 1.1 2014/02/13 06:56:30 keckhardt Exp $

--- gcc/lto/lto.c.orig	2014-02-12 22:02:51.000000000 +0000
+++ gcc/lto/lto.c
@@ -2469,7 +2469,11 @@ wait_for_child ()
   int status;
   do
     {
+#if defined(__NetBSD__)
+      int w = waitpid(0, &status, WUNTRACED | WALLSIG);
+#else
       int w = waitpid(0, &status, WUNTRACED | WCONTINUED);
+#endif
       if (w == -1)
 	fatal_error ("waitpid failed");
 
