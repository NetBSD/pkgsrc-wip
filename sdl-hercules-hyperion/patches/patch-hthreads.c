$NetBSD$

--- hthreads.c.orig	2020-02-08 18:02:21.803241719 +0000
+++ hthreads.c
@@ -279,9 +279,11 @@ DLL_EXPORT int  hthread_initialize_rwloc
     if (rc)
         goto fatal;
 
+#if !defined(__NetBSD__)
     rc = hthread_rwlockattr_setpshared( &attr1, HTHREAD_RWLOCK_DEFAULT );
     if (rc)
         goto fatal;
+#endif
 
     rc = hthread_mutexattr_settype( &attr2, HTHREAD_MUTEX_DEFAULT );
     if (rc)
