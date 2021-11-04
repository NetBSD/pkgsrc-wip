$NetBSD$

--- platforms/unix/vm/sqUnixITimerHeartbeat.c.orig	2018-10-19 04:12:21.000000000 +0000
+++ platforms/unix/vm/sqUnixITimerHeartbeat.c
@@ -305,7 +305,7 @@ static int handling_heartbeat = 0;
 #endif
 
 static void
-heartbeat_handler(int sig, struct siginfo *sig_info, void *context)
+heartbeat_handler(int sig, struct siginfo_t *sig_info, void *context)
 {
 #if !defined(SA_NODEFER)
 	/* if the CAS fails, the heartbeat is already being handled. */
