$NetBSD$

--- ../emu/thread_xsb.c.orig	2022-05-12 20:54:07.000000000 +0000
+++ ../emu/thread_xsb.c
@@ -20,6 +20,10 @@
 **
 */
 
+#if defined(__NetBSD__)
+#    define PTHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
