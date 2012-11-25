$NetBSD: patch-src_main.c,v 1.1 2012/11/25 17:53:11 pallegra Exp $

--- src/main.c.orig	2012-11-25 15:41:44.000000000 +0000
+++ src/main.c
@@ -219,11 +219,13 @@ static void i3_exit(void) {
     ev_loop_destroy(main_loop);
 #endif
 
+#if 0
     if (*shmlogname != '\0') {
         fprintf(stderr, "Closing SHM log \"%s\"\n", shmlogname);
         fflush(stderr);
         shm_unlink(shmlogname);
     }
+#endif
 }
 
 /*
@@ -234,10 +236,12 @@ static void i3_exit(void) {
  */
 static void handle_signal(int sig, siginfo_t *info, void *data) {
     fprintf(stderr, "Received signal %d, terminating\n", sig);
+#if 0
     if (*shmlogname != '\0') {
         fprintf(stderr, "Closing SHM log \"%s\"\n", shmlogname);
         shm_unlink(shmlogname);
     }
+#endif
     fflush(stderr);
     raise(sig);
 }
