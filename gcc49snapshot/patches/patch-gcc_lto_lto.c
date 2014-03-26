$NetBSD: patch-gcc_lto_lto.c,v 1.2 2014/03/26 16:23:57 keckhardt Exp $

--- gcc/lto/lto.c.orig	2014-03-19 11:35:59.000000000 +0000
+++ gcc/lto/lto.c
@@ -2479,7 +2479,12 @@ wait_for_child ()
 #ifndef WCONTINUED
 #define WCONTINUED 0
 #endif
-      int w = waitpid (0, &status, WUNTRACED | WCONTINUED);
+
+#if defined(__NetBSD__)
+      int w = waitpid(0, &status, WUNTRACED | WALLSIG);
+#else
+      int w = waitpid(0, &status, WUNTRACED | WCONTINUED);
+#endif
       if (w == -1)
 	fatal_error ("waitpid failed");
 
