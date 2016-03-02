$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/semaphore.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/semaphore.d
@@ -81,6 +81,12 @@ else version( FreeBSD )
 
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
@@ -137,6 +143,10 @@ else version( FreeBSD )
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
