$NetBSD$

Test for the actual define.

--- src/wx-thread.c.orig	2020-12-01 20:40:51.000000000 +0000
+++ src/wx-thread.c
@@ -171,7 +171,7 @@ int thread_wait_event(event_t *handle, i
 	event_pthread_t *event = (event_pthread_t *)handle;
 	struct timespec abstime;
 
-#ifdef __linux__
+#ifdef CLOCK_REALTIME
 	clock_gettime(CLOCK_REALTIME, &abstime);
 #else
         struct timeval now;
