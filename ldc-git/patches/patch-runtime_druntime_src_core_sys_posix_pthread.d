$NetBSD$

--- runtime/druntime/src/core/sys/posix/pthread.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/pthread.d
@@ -209,6 +209,57 @@ else version( FreeBSD )
     enum PTHREAD_COND_INITIALIZER               = null;
     enum PTHREAD_RWLOCK_INITIALIZER             = null;
 }
+ else version( NetBSD )
+{
+/* MISSING
+  PTHREAD_EXPLICIT_SCHED
+  PTHREAD_INHERIT_SCHED
+*/
+    enum
+    {
+        PTHREAD_CREATE_JOINABLE,
+        PTHREAD_CREATE_DETACHED,
+    }
+    enum
+    {
+        PTHREAD_INHERIT_SCHED,
+        PTHREAD_EXPLICIT_SCHED,
+    }
+    enum
+    {
+        PTHREAD_PROCESS_PRIVATE,
+        PTHREAD_PROCESS_SHARED,
+    }
+    enum
+    {
+        PTHREAD_CANCEL_DEFERRED,
+        PTHREAD_CANCEL_ASYNCHRONOUS,
+    }
+    enum
+    {
+        PTHREAD_CANCEL_ENABLE,
+        PTHREAD_CANCEL_DISABLE,
+    }
+    enum PTHREAD_BARRIER_SERIAL_THREAD = 1234567;
+/*
+ * POSIX 1003.1-2001, section 2.5.9.3: "The symbolic constant
+ * PTHREAD_CANCELED expands to a constant expression of type (void *)
+ * whose value matches no pointer to an object in memory nor the value
+ * NULL."
+ */
+    enum PTHREAD_CANCELED = cast(void*)1;
+
+/*
+ * Maximum length of a thread's name, including the terminating NUL.
+ */
+    enum PTHREAD_MAX_NAMELEN_NP = 32;
+
+    // enum PTHREAD_COND_INITIALIZER      = _PTHREAD_COND_INITIALIZER;
+    // enum PTHREAD_MUTEX_INITIALIZER     = _PTHREAD_MUTEX_INITIALIZER;
+    // enum PTHREAD_ONCE_INIT             = _PTHREAD_ONCE_INIT;
+    // enum PTHREAD_RWLOCK_INITIALIZER    = _PTHREAD_RWLOCK_INITIALIZER;
+    // enum PTHREAD_SPINLOCK_INITIALIZER  = _PTHREAD_SPINLOCK_INITIALIZER;
+}
 else version (Solaris)
 {
     enum
@@ -362,6 +413,31 @@ else version( FreeBSD )
     void __pthread_cleanup_push_imp(_pthread_cleanup_routine, void*, _pthread_cleanup_info*);
     void __pthread_cleanup_pop_imp(int);
 }
+else version( NetBSD )
+{
+    alias void function(void*) _pthread_cleanup_routine;
+
+    struct pthread_cleanup_store {
+        void*[4] pad;
+    }
+
+    struct pthread_cleanup
+    {
+        pthread_cleanup_store __store = void;
+
+        extern (D) void push()( _pthread_cleanup_routine routine, void* arg)
+        {
+ 	    pthread__cleanup_push(routine, arg, &__store);
+	}
+ 
+        extern (D) void pop()( int execute )
+        {
+            pthread__cleanup_pop(execute, &__store);
+ 	}
+    }
+    void pthread__cleanup_push(_pthread_cleanup_routine, void*, void*);
+    void pthread__cleanup_pop(int, void*);
+}
 else version (Solaris)
 {
     alias void function(void*) _pthread_cleanup_routine;
@@ -507,6 +583,16 @@ else version( FreeBSD )
     int pthread_barrierattr_init(pthread_barrierattr_t*);
     int pthread_barrierattr_setpshared(pthread_barrierattr_t*, int);
 }
+else version( NetBSD )
+{
+    int pthread_barrier_destroy(pthread_barrier_t*);
+    int pthread_barrier_init(pthread_barrier_t*, in pthread_barrierattr_t*, uint);
+    int pthread_barrier_wait(pthread_barrier_t*);
+    int pthread_barrierattr_destroy(pthread_barrierattr_t*);
+//int pthread_barrierattr_getpshared(in pthread_barrierattr_t*, int*); (BAR|TSH)
+    int pthread_barrierattr_init(pthread_barrierattr_t*);
+//int pthread_barrierattr_setpshared(pthread_barrierattr_t*, int); (BAR|TSH)
+}
 else version (OSX)
 {
 }
@@ -565,6 +651,14 @@ else version( FreeBSD )
     int pthread_spin_trylock(pthread_spinlock_t*);
     int pthread_spin_unlock(pthread_spinlock_t*);
 }
+else version( NetBSD )
+{
+    int pthread_spin_init(pthread_spinlock_t*, int);
+    int pthread_spin_destroy(pthread_spinlock_t*);
+    int pthread_spin_lock(pthread_spinlock_t*);
+    int pthread_spin_trylock(pthread_spinlock_t*);
+    int pthread_spin_unlock(pthread_spinlock_t*);
+}
 else version (OSX)
 {
 }
@@ -648,6 +742,27 @@ else version( FreeBSD )
     int pthread_mutexattr_settype(pthread_mutexattr_t*, int) @trusted;
     int pthread_setconcurrency(int);
 }
+else version( NetBSD )
+{
+    /*
+     * Mutex attributes.
+     */
+    enum
+    {
+        PTHREAD_MUTEX_NORMAL,
+        PTHREAD_MUTEX_ERRORCHECK,
+        PTHREAD_MUTEX_RECURSIVE,
+        PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL,
+    }
+    int pthread_attr_getguardsize(in pthread_attr_t*, size_t*);
+    int pthread_attr_setguardsize(pthread_attr_t*, size_t);
+    int pthread_mutexattr_gettype(in pthread_mutexattr_t*, int*);
+    int pthread_mutexattr_settype(pthread_mutexattr_t*, int);
+/* MISSING:
+int pthread_getconcurrency();
+int pthread_setconcurrency(int);
+*/
+}
 else version (Solaris)
 {
     enum
@@ -698,6 +813,9 @@ else version( FreeBSD )
 {
     int pthread_getcpuclockid(pthread_t, clockid_t*);
 }
+else version( NetBSD )
+{
+}
 else version (OSX)
 {
 }
@@ -740,6 +858,14 @@ else version( FreeBSD )
     int pthread_rwlock_timedrdlock(pthread_rwlock_t*, in timespec*);
     int pthread_rwlock_timedwrlock(pthread_rwlock_t*, in timespec*);
 }
+else version( NetBSD )
+{
+     /* MISSING:
+      *int pthread_mutex_timedlock(pthread_mutex_t*, in timespec*);
+      */
+    int pthread_rwlock_timedrdlock(pthread_rwlock_t*, in timespec*);
+    int pthread_rwlock_timedwrlock(pthread_rwlock_t*, in timespec*);
+}
 else version (Solaris)
 {
     int pthread_mutex_timedlock(pthread_mutex_t*, in timespec*);
@@ -876,6 +1002,27 @@ else version( FreeBSD )
     int pthread_setschedparam(pthread_t, int, sched_param*);
     // int pthread_setschedprio(pthread_t, int); // not implemented
 }
+else version( NetBSD )
+{
+    enum
+    {
+        PTHREAD_SCOPE_PROCESS,
+	PTHREAD_SCOPE_SYSTEM,
+    }
+
+int pthread_attr_getinheritsched(in pthread_attr_t*, int*);
+int pthread_attr_getschedpolicy(in pthread_attr_t*, int*);
+int pthread_attr_getscope(in pthread_attr_t*, int*);
+int pthread_attr_setinheritsched(pthread_attr_t*, int);
+int pthread_attr_setschedpolicy(pthread_attr_t*, int);
+int pthread_attr_setscope(pthread_attr_t*, int);
+int pthread_getschedparam(pthread_t, int*, sched_param*);
+int pthread_setschedparam(pthread_t, int, in sched_param*);
+
+/* MISSING:
+int pthread_setschedprio(pthread_t, int);
+*/
+}
 else version (Solaris)
 {
     enum
@@ -953,6 +1100,15 @@ else version( FreeBSD )
     int pthread_attr_setstackaddr(pthread_attr_t*, void*);
     int pthread_attr_setstacksize(pthread_attr_t*, size_t);
 }
+else version( NetBSD )
+{
+    int pthread_attr_getstack(in pthread_attr_t*, void**, size_t*);
+    int pthread_attr_getstackaddr(in pthread_attr_t*, void**);
+    int pthread_attr_getstacksize(in pthread_attr_t*, size_t*);
+    int pthread_attr_setstack(pthread_attr_t*, void*, size_t);
+    int pthread_attr_setstackaddr(pthread_attr_t*, void*);
+    int pthread_attr_setstacksize(pthread_attr_t*, size_t);
+}
 else version (Solaris)
 {
     int pthread_attr_getstack(in pthread_attr_t*, void**, size_t*);
@@ -1006,6 +1162,17 @@ else version( FreeBSD )
     int pthread_rwlockattr_getpshared(in pthread_rwlockattr_t*, int*);
     int pthread_rwlockattr_setpshared(pthread_rwlockattr_t*, int);
 }
+else version( NetBSD )
+{
+/* MISSING:
+int pthread_condattr_getpshared(in pthread_condattr_t*, int*);
+int pthread_condattr_setpshared(pthread_condattr_t*, int);
+int pthread_mutexattr_getpshared(in pthread_mutexattr_t*, int*);
+int pthread_mutexattr_setpshared(pthread_mutexattr_t*, int);
+int pthread_rwlockattr_getpshared(in pthread_rwlockattr_t*, int*);
+int pthread_rwlockattr_setpshared(pthread_rwlockattr_t*, int);
+*/
+}
 else version( OSX )
 {
     int pthread_condattr_getpshared(in pthread_condattr_t*, int*);
