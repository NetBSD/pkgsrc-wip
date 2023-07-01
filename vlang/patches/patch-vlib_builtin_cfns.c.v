$NetBSD$

We don't have pthread_rwlockattr_setpshared().

--- vlib/builtin/cfns.c.v.orig	2023-06-29 19:16:34.000000000 +0000
+++ vlib/builtin/cfns.c.v
@@ -422,7 +422,7 @@ fn C.pthread_rwlockattr_init(voidptr) in
 
 fn C.pthread_rwlockattr_setkind_np(voidptr, int) int
 
-fn C.pthread_rwlockattr_setpshared(voidptr, int) int
+// fn C.pthread_rwlockattr_setpshared(voidptr, int) int
 
 fn C.pthread_rwlock_init(voidptr, voidptr) int
 
