$NetBSD$

Define variable rwlockatt
(missing for codepath without XSI extension or POSIX.1-2008).

--- lib/FXReadWriteLock.cpp.orig	2022-02-15 03:49:40.000000000 +0000
+++ lib/FXReadWriteLock.cpp
@@ -79,6 +79,7 @@ FXReadWriteLock::FXReadWriteLock(){
   // machine and mail it to: jeroen@fox-toolkit.net!!
   //FXTRACE((150,"sizeof(pthread_rwlock_t)=%d\n",sizeof(pthread_rwlock_t)));
   FXASSERT_STATIC(sizeof(data)>=sizeof(pthread_rwlock_t));
+  pthread_rwlockattr_t rwlockatt;
   pthread_rwlock_init((pthread_rwlock_t*)data,&rwlockatt);
 #endif
   }
