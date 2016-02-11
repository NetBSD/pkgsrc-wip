$NetBSD$

--- runtime/druntime/src/core/sys/posix/semaphore.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/semaphore.d
@@ -81,6 +81,23 @@ else version( FreeBSD )
 
     enum SEM_FAILED = cast(sem_t*) null;
 }
+else version( NetBSD )
+{
+    import core.stdc.stdint;
+    struct _sem_st
+    {
+        uint	ksem_magic;
+        struct Ksem_list
+	{
+            _sem_st*  le_next;	/* next element */
+            _sem_st** le_prev;	/* address of previous next element */
+        }
+  	Ksem_list ksem_list;
+  	intptr_t		ksem_semid;	/* 0 -> user (non-shared) */
+  	sem_t		*ksem_identity;
+    }
+    alias _sem_st* sem_t;
+}
 else version (Solaris)
 {
     struct sem_t
@@ -137,6 +154,10 @@ else version( FreeBSD )
 {
     int sem_timedwait(sem_t*, in timespec*);
 }
+else version( NetBSD )
+{
+    int sem_timedwait(sem_t*, in timespec*);
+}
 else version (Solaris)
 {
     int sem_timedwait(sem_t*, in timespec*);
