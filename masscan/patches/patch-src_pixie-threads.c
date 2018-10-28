$NetBSD$

Treats NetBSD like {Free,Open}BSD

--- src/pixie-threads.c.orig	2017-06-06 03:59:39.000000000 +0000
+++ src/pixie-threads.c
@@ -12,7 +12,7 @@
 #include <errno.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -122,7 +122,7 @@ pixie_cpu_get_count(void)
         return 1;
     else
         return count;
-#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     /* BSD - use sysctl() function */
         int x;
         int mib[2];
@@ -180,7 +180,7 @@ pixie_begin_thread(
 #if defined(WIN32)
     UNUSEDPARM(flags);
     return _beginthread(worker_thread, 0, worker_data);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__kFreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__kFreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
     typedef void *(*PTHREADFUNC)(void*);
     pthread_t thread_id = 0;
