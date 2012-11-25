$NetBSD: patch-src_log.c,v 1.1 2012/11/25 17:53:11 pallegra Exp $

--- src/log.c.orig	2012-11-25 15:55:29.000000000 +0000
+++ src/log.c
@@ -108,7 +108,7 @@ void init_logging(void) {
 #endif
         logbuffer_size = min(physical_mem_bytes * 0.01, shmlog_size);
         sasprintf(&shmlogname, "/i3-log-%d", getpid());
-        logbuffer_shm = shm_open(shmlogname, O_RDWR | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
+        logbuffer_shm = -1;
         if (logbuffer_shm == -1) {
             ELOG("Could not shm_open SHM segment for the i3 log: %s\n", strerror(errno));
             return;
