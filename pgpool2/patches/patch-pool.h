$NetBSD: patch-pool.h,v 1.1 2013/05/02 20:02:42 fhajny Exp $

Default pid file location.
--- pool.h.orig	2013-04-26 05:52:44.000000000 +0000
+++ pool.h
@@ -67,7 +67,7 @@
 #define DEFAULT_SOCKET_DIR "/tmp"
 
 /* pid file name */
-#define DEFAULT_PID_FILE_NAME "/var/run/pgpool/pgpool.pid"
+#define DEFAULT_PID_FILE_NAME "@PGPOOL_PIDDIR@/pgpool.pid"
 
 /* status file name */
 #define STATUS_FILE_NAME "pgpool_status"
