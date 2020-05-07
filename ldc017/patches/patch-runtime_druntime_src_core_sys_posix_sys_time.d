$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/time.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/time.d
@@ -149,6 +149,27 @@ else version( DragonFlyBSD )
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
+
+    int getitimer(int, itimerval*);
+    int gettimeofday(timeval*, void*); // timezone_t* is normally void*
+    int setitimer(int, in itimerval*, itimerval*);
+    int utimes(in char*, ref const(timeval)[2]);
+}
+
 else version (Solaris)
 {
     struct timeval
