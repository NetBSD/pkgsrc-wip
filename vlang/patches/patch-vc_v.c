$NetBSD$

We don't have pthread_rwlockattr_setpshared().

--- vc/v.c.orig	2023-06-29 20:59:49.000000000 +0000
+++ vc/v.c
@@ -44589,7 +44589,7 @@ void sync__RwMutex_init(sync__RwMutex* m
 	sync__RwMutexAttr a = ((sync__RwMutexAttr){EMPTY_STRUCT_INITIALIZATION});
 	pthread_rwlockattr_init(&a.attr);
 	pthread_rwlockattr_setkind_np(&a.attr, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
-	pthread_rwlockattr_setpshared(&a.attr, PTHREAD_PROCESS_PRIVATE);
+	// pthread_rwlockattr_setpshared(&a.attr, PTHREAD_PROCESS_PRIVATE);
 	pthread_rwlock_init(&m->mutex, &a.attr);
 	pthread_rwlockattr_destroy(&a.attr);
 }
