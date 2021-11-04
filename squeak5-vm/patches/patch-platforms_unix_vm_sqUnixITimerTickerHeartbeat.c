$NetBSD$

--- platforms/unix/vm/sqUnixITimerTickerHeartbeat.c.orig	2018-11-05 16:37:13.052717036 +0000
+++ platforms/unix/vm/sqUnixITimerTickerHeartbeat.c
@@ -329,7 +329,7 @@ prodHighPriorityThread()
 }
 
 static void
-high_performance_tick_handler(int sig, struct siginfo *sig_info, void *context)
+high_performance_tick_handler(int sig, struct siginfo_t *sig_info, void *context)
 {
 static int tickCheckInProgress;
 
