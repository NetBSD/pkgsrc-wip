$NetBSD$

We don't have pthread_rwlockattr_setpshared().

--- vlib/sync/sync_default.c.v.orig	2022-04-18 11:25:57.000000000 +0000
+++ vlib/sync/sync_default.c.v
@@ -20,7 +20,7 @@ fn C.pthread_mutex_unlock(voidptr) int
 fn C.pthread_mutex_destroy(voidptr) int
 fn C.pthread_rwlockattr_init(voidptr) int
 fn C.pthread_rwlockattr_setkind_np(voidptr, int) int
-fn C.pthread_rwlockattr_setpshared(voidptr, int) int
+// fn C.pthread_rwlockattr_setpshared(voidptr, int) int
 fn C.pthread_rwlock_init(voidptr, voidptr) int
 fn C.pthread_rwlock_rdlock(voidptr) int
 fn C.pthread_rwlock_wrlock(voidptr) int
@@ -85,7 +85,7 @@ pub fn (mut m RwMutex) init() {
 	C.pthread_rwlockattr_init(&a.attr)
 	// Give writer priority over readers
 	C.pthread_rwlockattr_setkind_np(&a.attr, C.PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP)
-	C.pthread_rwlockattr_setpshared(&a.attr, C.PTHREAD_PROCESS_PRIVATE)
+	// C.pthread_rwlockattr_setpshared(&a.attr, C.PTHREAD_PROCESS_PRIVATE)
 	C.pthread_rwlock_init(&m.mutex, &a.attr)
 }
 
