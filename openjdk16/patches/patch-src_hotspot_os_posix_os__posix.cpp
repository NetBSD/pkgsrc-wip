$NetBSD: patch-src_hotspot_os_posix_os__posix.cpp,v 1.1 2019/10/01 12:36:34 tnn Exp $

Something is wrong with pthread_condattr_setclock.
We hit assertions in fastdebug builds.
Disable pthread_condattr_setclock for now.

--- src/hotspot/os/posix/os_posix.cpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/os/posix/os_posix.cpp	2021-06-10 13:30:56.931826833 -0400
@@ -1238,6 +1238,7 @@
 
   // 2. Check for pthread_condattr_setclock support.
 
+#if !defined(__NetBSD__)
   // libpthread is already loaded.
   int (*condattr_setclock_func)(pthread_condattr_t*, clockid_t) =
     (int (*)(pthread_condattr_t*, clockid_t))dlsym(RTLD_DEFAULT,
@@ -1245,6 +1246,7 @@
   if (condattr_setclock_func != NULL) {
     _pthread_condattr_setclock = condattr_setclock_func;
   }
+#endif
 
   // Now do general initialization.
 
