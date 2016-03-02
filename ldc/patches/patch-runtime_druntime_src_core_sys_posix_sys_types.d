$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/types.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/types.d
@@ -138,6 +138,23 @@ else version( FreeBSD )
     alias uint      uid_t;
     alias uint      fflags_t;
 }
+else version( NetBSD )
+{
+    alias long      blkcnt_t;
+    alias int       blksize_t;
+    alias ulong     dev_t;
+    alias uint      gid_t;
+    alias ulong     ino_t;
+    alias uint      mode_t;
+    alias uint      nlink_t;
+    alias ulong     off_t;
+    alias int       pid_t;
+    //size_t (defined in core.stdc.stddef)
+    alias c_long      ssize_t;
+    alias c_long      time_t;
+    alias uint        uid_t;
+
+}
 else version (Solaris)
 {
     alias char* caddr_t;
@@ -269,6 +286,16 @@ else version( FreeBSD )
     alias c_long    suseconds_t;
     alias uint      useconds_t;
 }
+else version( NetBSD )
+{
+    alias ulong     fsblkcnt_t;
+    alias ulong     fsfilcnt_t;
+    alias c_long    clock_t;
+    alias long      id_t;
+    alias c_long    key_t;
+    alias c_long    suseconds_t;
+    alias uint      useconds_t;
+}
 else version (Solaris)
 {
     static if (__USE_FILE_OFFSET64)
@@ -645,6 +672,31 @@ else version( FreeBSD )
     alias void* pthread_rwlockattr_t;
     alias void* pthread_t;
 }
+else version( NetBSD )
+{
+    alias int lwpid_t;
+
+    struct pthread_attr_t_ {ubyte[16] a;};
+    struct pthread_cond_t_ {ubyte[40] a;};
+    struct pthread_condattr_t_ {ubyte[16] a;};
+    struct pthread_mutex_t_ {ubyte[48] a;};
+    struct pthread_mutexattr_t_{ubyte[16] a;};
+    struct pthread_once_t_{ubyte[56] a;};
+    struct pthread_rwlock_t_{ubyte[64] a;};
+    struct pthread_rwlockattr_t_{ubyte[16] a;};
+
+    alias pthread_attr_t_ pthread_attr_t;
+    alias pthread_cond_t_ pthread_cond_t;
+    alias pthread_condattr_t_ pthread_condattr_t;
+    alias uint pthread_key_t;
+    alias pthread_mutex_t_ pthread_mutex_t;
+    alias pthread_mutexattr_t_ pthread_mutexattr_t;
+    alias pthread_once_t_ pthread_once_t;
+    alias pthread_rwlock_t_ pthread_rwlock_t;
+    alias pthread_rwlockattr_t_ pthread_rwlockattr_t;
+
+    alias void* pthread_t;
+}
 else version (Solaris)
 {
     alias uint pthread_t;
@@ -809,6 +861,11 @@ else version( FreeBSD )
     alias void* pthread_barrier_t;
     alias void* pthread_barrierattr_t;
 }
+else version( NetBSD )
+{
+    alias void* pthread_barrier_t;
+    alias void* pthread_barrierattr_t;
+}
 else version( OSX )
 {
 }
@@ -852,6 +909,10 @@ else version( FreeBSD )
 {
     alias void* pthread_spinlock_t;
 }
+else version( NetBSD )
+{
+    alias void* pthread_spinlock_t;
+}
 else version (Solaris)
 {
     alias pthread_mutex_t pthread_spinlock_t;
