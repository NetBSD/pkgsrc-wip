$NetBSD$

We don't have pthread_rwlockattr_setpshared().

--- vlib/builtin/cfns.c.v.orig	2022-04-18 11:25:57.000000000 +0000
+++ vlib/builtin/cfns.c.v
@@ -413,7 +413,7 @@ fn C.pthread_rwlockattr_init(voidptr) in
 
 fn C.pthread_rwlockattr_setkind_np(voidptr, int) int
 
-fn C.pthread_rwlockattr_setpshared(voidptr, int) int
+//fn C.pthread_rwlockattr_setpshared(voidptr, int) int
 
 fn C.pthread_rwlock_init(voidptr, voidptr) int
 
