$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/synchronization/lock_impl.h.orig	2024-10-18 12:33:59.810249600 +0000
+++ base/synchronization/lock_impl.h
@@ -109,6 +109,10 @@ void LockImpl::Unlock() {
 }
 
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
+#endif
 
 #if DCHECK_IS_ON()
 BASE_EXPORT void dcheck_trylock_result(int rv);
@@ -129,6 +133,9 @@ void LockImpl::Unlock() {
   dcheck_unlock_result(rv);
 #endif
 }
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic pop
+#endif
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
