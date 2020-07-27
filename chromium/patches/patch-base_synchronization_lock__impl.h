$NetBSD$

--- base/synchronization/lock_impl.h.orig	2020-07-08 21:40:31.000000000 +0000
+++ base/synchronization/lock_impl.h
@@ -69,9 +69,12 @@ void LockImpl::Unlock() {
   ::ReleaseSRWLockExclusive(reinterpret_cast<PSRWLOCK>(&native_handle_));
 }
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
+//#pragma GCC diagnostic push
+//#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
 void LockImpl::Unlock() {
   int rv = pthread_mutex_unlock(&native_handle_);
   DCHECK_EQ(rv, 0) << ". " << strerror(rv);
+//#pragma GCC diagnostic pop
 }
 #endif
 
