$NetBSD: patch-pool.h,v 1.2 2014/05/07 09:19:27 fhajny Exp $

Default pid file location.
--- pool.h.orig	2014-03-24 14:30:01.000000000 +0000
+++ pool.h
@@ -67,7 +67,7 @@
 #define DEFAULT_SOCKET_DIR "/tmp"
 
 /* pid file name */
-#define DEFAULT_PID_FILE_NAME "/var/run/pgpool/pgpool.pid"
+#define DEFAULT_PID_FILE_NAME "@PGPOOL_PIDDIR@/pgpool.pid"
 
 /* status file name */
 #define STATUS_FILE_NAME "pgpool_status"
