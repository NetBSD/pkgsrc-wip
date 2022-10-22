$NetBSD$

* use posix standard defines instead of linux ones,
  needed on NetBSD

--- src/threads/mutex.cpp.orig	2022-02-19 05:05:00.000000000 +0000
+++ src/threads/mutex.cpp
@@ -36,7 +36,7 @@ t_mutex::t_mutex(bool recursive) {
 	pthread_mutexattr_init(&attr);
 
 
-	int ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
+	int ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 	if (ret != 0) throw string(
 		"t_mutex::t_mutex failed to create a recursive mutex.");
 
