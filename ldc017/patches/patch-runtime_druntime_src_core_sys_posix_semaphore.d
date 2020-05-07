$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/semaphore.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/semaphore.d
@@ -96,6 +96,12 @@ else version( DragonFlyBSD )
 
     enum SEM_FAILED = cast(sem_t*) null;
 }
+else version( NetBSD )
+{
+    alias size_t sem_t;
+
+    enum SEM_FAILED = cast(sem_t*) null;
+}
 else version (Solaris)
 {
     struct sem_t
@@ -156,6 +162,10 @@ else version( DragonFlyBSD )
 {
     int sem_timedwait(sem_t*, in timespec*);
 }
+else version ( NetBSD )
+{
+    int sem_timedwait(sem_t*, in timespec*);
+}
 else version (Solaris)
 {
     int sem_timedwait(sem_t*, in timespec*);
