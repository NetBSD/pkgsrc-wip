$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/time.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/time.d
@@ -123,6 +123,34 @@ else version( FreeBSD )
     int setitimer(int, in itimerval*, itimerval*);
     int utimes(in char*, ref const(timeval)[2]);
 }
+else version( NetBSD )
+{     
+    struct timeval
+    {
+        time_t      tv_sec;
+        suseconds_t tv_usec;
+    }
+
+    struct itimerval
+    {
+        timeval it_interval;
+        timeval it_value;
+    }
+
+    enum
+    {
+        ITIMER_REAL,
+	ITIMER_VIRTUAL,
+	ITIMER_PROF,
+	ITIMER_MONOTONIC,
+    }
+
+    int getitimer(int, itimerval*);
+    int gettimeofday(timeval*, void*);
+//int select(int, fd_set*, fd_set*, fd_set*, timeval*); (defined in core.sys.posix.sys.signal)
+    int setitimer(int, in itimerval*, itimerval*);
+    int utimes(in char*, ref const(timeval)[2]); // LEGACY
+}
 else version (Solaris)
 {
     struct timeval
