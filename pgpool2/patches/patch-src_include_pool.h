$NetBSD: patch-src_include_pool.h,v 1.1 2015/04/13 19:59:59 fhajny Exp $

Default pid file location.
--- src/include/pool.h.orig	2015-04-08 07:58:44.000000000 +0000
+++ src/include/pool.h
@@ -78,7 +78,7 @@
 #define DEFAULT_SOCKET_DIR "/tmp"
 
 /* pid file name */
-#define DEFAULT_PID_FILE_NAME "/var/run/pgpool/pgpool.pid"
+#define DEFAULT_PID_FILE_NAME "@PGPOOL_PIDDIR@/pgpool.pid"
 
 /* status file name */
 #define STATUS_FILE_NAME "pgpool_status"
