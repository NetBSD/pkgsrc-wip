@NetBSD@

Do not override our parallel make choice.
--- getarch.c.orig	2018-04-03 12:56:19.322128443 +0200
+++ getarch.c	2018-04-03 12:57:42.424122776 +0200
@@ -1134,21 +1134,6 @@
 #endif
 #endif
 
-#ifdef MAKE_NB_JOBS
-  #if MAKE_NB_JOBS > 0
-    printf("MAKE += -j %d\n", MAKE_NB_JOBS);
-  #else
-    // Let make use parent -j argument or -j1 if there
-    // is no make parent
-  #endif
-#elif NO_PARALLEL_MAKE==1
-    printf("MAKE += -j 1\n");
-#else
-#ifndef OS_WINDOWS
-    printf("MAKE += -j %d\n", get_num_cores());
-#endif
-#endif
-
     break;
 
   case '1' : /* For config.h */
