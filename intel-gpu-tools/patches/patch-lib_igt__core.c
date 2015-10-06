$NetBSD$

--- lib/igt_core.c.orig	2015-09-08 15:15:16.000000000 +0000
+++ lib/igt_core.c
@@ -1483,8 +1483,10 @@ static void fatal_sig_handler(int sig)
 		pthread_t tid = pthread_self();
 		union sigval value = { .sival_ptr = NULL };
 
+#ifndef __NetBSD__ /* XXX */
 		pthread_sigqueue(tid, sig, value);
 #endif
+#endif
         }
 }
 
