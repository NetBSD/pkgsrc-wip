$NetBSD: patch-src_log.c,v 1.3 2014/08/09 19:14:01 degroote Exp $

Use ftruncate(2) instead of posix_fallocate(2) on NetBSD.
Do not set process-shared attribute on NetBSD.

--- src/log.c.orig	2016-01-11 23:36:55.000000000 +0000
+++ src/log.c
@@ -129,7 +129,7 @@ void open_logbuffer(void) {
         return;
     }
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
     if (ftruncate(logbuffer_shm, logbuffer_size) == -1) {
         fprintf(stderr, "Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
 #else
@@ -156,8 +156,10 @@ void open_logbuffer(void) {
 
     pthread_condattr_t cond_attr;
     pthread_condattr_init(&cond_attr);
+#if !defined(__NetBSD__)
     if (pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED) != 0)
         fprintf(stderr, "pthread_condattr_setpshared() failed, i3-dump-log -f will not work!\n");
+#endif
     pthread_cond_init(&(header->condvar), &cond_attr);
 
     logwalk = logbuffer + sizeof(i3_shmlog_header);
