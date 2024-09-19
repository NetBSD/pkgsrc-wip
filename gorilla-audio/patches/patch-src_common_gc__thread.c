$NetBSD$

NetBSD support.

--- src/common/gc_thread.c.orig	2020-12-07 09:04:06.000000000 +0000
+++ src/common/gc_thread.c
@@ -49,7 +49,7 @@ void ga_thread_destroy(GaThread *thread)
 	gcX_ops->freeFunc(thread);
 }
 
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <pthread.h>
 #include <sched.h>
 
@@ -96,7 +96,7 @@ GaThread* ga_thread_create(GaCbThreadFun
 	pthread_mutex_lock(&thread_data->suspend_mutex);
 
 	if (pthread_attr_init(&thread_data->attr) != 0){} // report error
-#if defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	param.sched_priority = priorityLut[priority];
 #elif defined(__linux__)
 	param.__sched_priority = priorityLut[priority];
@@ -162,7 +162,7 @@ void ga_mutex_unlock(GaMutex *mutex) {
 	LeaveCriticalSection((CRITICAL_SECTION*)mutex->mutex);
 }
 
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
 #include <pthread.h>
 
