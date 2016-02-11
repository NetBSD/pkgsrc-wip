$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/types.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/types.d
@@ -138,6 +138,29 @@ else version( FreeBSD )
     alias uint      uid_t;
     alias uint      fflags_t;
 }
+else version( NetBSD )
+{
+    alias long      blkcnt_t;
+    alias int	    blksize_t;
+    alias ulong	    dev_t;
+    alias uint	    gid_t;
+    alias ulong	    ino_t;
+    alias uint	    mode_t;
+    alias uint	    nlink_t;
+    alias long	    off_t;
+    alias int	    pid_t;
+    //size_t (defined in core.stdc.stddef)
+    version (D_LP64)  //TODO: There are more rules to follow.
+    {
+	alias long  ssize_t;
+    }
+    else
+    {
+	alias int   ssize_t;
+    }
+    alias long      time_t;
+    alias uint	    uid_t;
+}
 else version (Solaris)
 {
     alias char* caddr_t;
@@ -269,6 +292,16 @@ else version( FreeBSD )
     alias c_long    suseconds_t;
     alias uint      useconds_t;
 }
+else version( NetBSD )
+{
+    alias uint      clock_t;
+    alias ulong	    fsblkcnt_t;
+    alias ulong	    fsfilcnt_t;
+    alias uint	    id_t;
+    alias c_long    key_t;
+    alias int	    suseconds_t;
+    alias uint      useconds_t;
+}
 else version (Solaris)
 {
     static if (__USE_FILE_OFFSET64)
@@ -645,6 +678,24 @@ else version( FreeBSD )
     alias void* pthread_rwlockattr_t;
     alias void* pthread_t;
 }
+else version ( NetBSD )
+{
+    alias int lwpid_t;
+
+    alias void** pthread_t;
+    alias void* pthread_attr_t;
+    alias void* pthread_mutex_t;
+    alias void* pthread_mutexattr_t;
+    alias void* pthread_cond_t;
+    alias void* pthread_condattr_t;
+    alias void* pthread_once_t;
+    alias void* pthread_spinlock_t;
+    alias void* pthread_rwlock_t;
+    alias void* pthread_rwlockattr_t;
+    // alias void* pthread_barrier_t;
+    // alias void* pthread_barrierattr_t;
+    alias int pthread_key_t;
+}
 else version (Solaris)
 {
     alias uint pthread_t;
@@ -809,6 +860,34 @@ else version( FreeBSD )
     alias void* pthread_barrier_t;
     alias void* pthread_barrierattr_t;
 }
+else version( NetBSD )
+{
+    alias void* pthread_barrier_t;
+    alias void* pthread_barrierattr_t;
+}
+/+
+    alias __pthread_barrier_st pthread_barrier_t;
+    alias __pthread_barrierattr_st pthread_barrierattr_t;
+
+    struct __pthread_barrier_st {
+        uint    ptb_magic;
+ 
+        /* Protects data below */
+        pthread_spin_t	ptb_lock;
+ 
+        pthread_queue_t	ptb_waiters;
+        uint    ptb_initcount;
+        uint    ptb_curcount;
+        uint    ptb_generation;
+ 
+        void*  	ptb_private;
+    };
+ 
+    struct __pthread_barrierattr_st {
+        uint    ptba_magic;
+        void*   ptba_private;
+    };
++/
 else version( OSX )
 {
 }
