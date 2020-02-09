$NetBSD$

pthread_rwlockattr_setpshared(3) is hidden on NetBSD; use configure to check for it.

--- hthreads.h.orig	2019-09-10 18:06:20.000000000 +0000
+++ hthreads.h
@@ -164,7 +164,11 @@ typedef pthread_rwlock_t        HRWLOCK;
 #define hthread_mutex_destroy( plk )            pthread_mutex_destroy( plk )
 
 #define hthread_rwlockattr_init( pla )          pthread_rwlockattr_init( pla )
-#define hthread_rwlockattr_setpshared( pla, s ) pthread_rwlockattr_setpshared( (pla), (s) )
+#if HAVE_PTHREAD_RWLOCKATTR_SETPSHARED
+# define hthread_rwlockattr_setpshared( pla, s ) pthread_rwlockattr_setpshared( (pla), (s) )
+#else /* HAVE_PTHREAD_RWLOCKATTR_SETPSHARED*/
+# define hthread_rwlockattr_setpshared( pla, s ) 0
+#endif /* HAVE_PTHREAD_RWLOCKATTR_SETPSHARED*/
 #define hthread_rwlockattr_destroy( pla )       pthread_rwlockattr_destroy( pla )
 
 #define hthread_rwlock_init( plk, pla )         pthread_rwlock_init( (plk), (pla) )
