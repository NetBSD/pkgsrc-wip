$NetBSD$

--- runtime/druntime/src/core/sys/posix/time.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/time.d
@@ -52,6 +52,10 @@ else version( FreeBSD )
 {
     time_t timegm(tm*); // non-standard
 }
+else version( NetBSD )
+{
+    time_t timegm(tm*); // non-standard
+}
 else version (Solaris)
 {
     time_t timegm(tm*); // non-standard
@@ -115,6 +119,10 @@ else version (FreeBSD)
     deprecated("Please import it from core.sys.freebsd.time instead.")
         alias CLOCK_MONOTONIC_FAST = core.sys.freebsd.time.CLOCK_MONOTONIC_FAST;
 }
+else version( NetBSD )
+{
+    enum CLOCK_MONOTONIC =3;
+}
 else version (OSX)
 {
     // No CLOCK_MONOTONIC defined
@@ -245,6 +253,43 @@ else version( FreeBSD )
     int timer_getoverrun(timer_t);
     int timer_settime(timer_t, int, in itimerspec*, itimerspec*);
 }
+ else version( NetBSD )
+{
+  // MISSING:
+  /*
+CLOCK_PROCESS_CPUTIME_ID (TMR|CPT)
+CLOCK_THREAD_CPUTIME_ID (TMR|TCT)
+  */
+// NOTE: timespec must be defined in core.sys.posix.signal to break
+//       a circular import.
+    // struct timespec
+    // {
+    //     time_t tv_sec;
+    //     c_long tv_nsec;
+    // }
+
+    struct itimerspec
+    {
+      timespec it_interval;
+      timespec it_value;
+    }
+
+    enum CLOCK_REALTIME = 0;
+    enum TIMER_ABSTIME  = 0;
+
+    alias int clockid_t;
+    alias int timer_t;
+
+    int clock_getres(clockid_t, timespec*);
+    int clock_gettime(clockid_t, timespec*);
+    int clock_settime(clockid_t, in timespec*);
+    int nanosleep(in timespec*, timespec*);
+    int timer_create(clockid_t, sigevent*, timer_t*);
+    int timer_delete(timer_t);
+    int timer_gettime(timer_t, itimerspec*);
+    int timer_getoverrun(timer_t);
+    int timer_settime(timer_t, int, in itimerspec*, itimerspec*);
+}
 else version (Solaris)
 {
     enum CLOCK_PROCESS_CPUTIME_ID = 5; // <sys/time_impl.h>
@@ -338,6 +383,13 @@ else version( FreeBSD )
     tm*   gmtime_r(in time_t*, tm*);
     tm*   localtime_r(in time_t*, tm*);
 }
+else version( NetBSD )
+{
+    char* asctime_r(in tm*, char*);
+    char* ctime_r(in time_t*, char*);
+    tm*   gmtime_r(in time_t*, tm*);
+    tm*   localtime_r(in time_t*, tm*);
+}
 else version (Solaris)
 {
     char* asctime_r(in tm*, char*);
@@ -391,6 +443,13 @@ else version( FreeBSD )
     //tm*   getdate(in char*);
     char* strptime(in char*, in char*, tm*);
 }
+else version( NetBSD )
+{
+    extern __gshared int    daylight;
+
+    tm*   getdate(in char*);
+    char* strptime(in char*, in char*, tm*);
+}
 else version (Solaris)
 {
     extern __gshared c_long timezone, altzone;
