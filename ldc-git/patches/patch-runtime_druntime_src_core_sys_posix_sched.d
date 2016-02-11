$NetBSD$

--- runtime/druntime/src/core/sys/posix/sched.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sched.d
@@ -86,6 +86,29 @@ else version( FreeBSD )
     enum SCHED_OTHER    = 2;
     enum SCHED_RR       = 3;
 }
+else version( NetBSD )
+{
+  struct sched_param {
+    int sched_priority;
+  }
+
+/* MISSING:
+SCHED_SPORADIC (SS|TSP)
+*/
+
+  enum
+  {
+    SCHED_NONE = -1,
+    SCHED_OTHER,
+    SCHED_FIFO,
+    SCHED_RR,
+  }
+
+  int _sched_getparam(pid_t, lwpid_t, int*, sched_param*);
+  int _sched_getscheduler(pid_t);
+  int _sched_setparam(pid_t, lwpid_t, int, const sched_param*);
+  int _sched_setscheduler(pid_t, int, const sched_param*);
+}
 else version (Solaris)
 {
     struct sched_param
@@ -144,6 +167,10 @@ else version( FreeBSD )
 {
     int sched_yield();
 }
+else version( NetBSD )
+{
+    int sched_yield();
+}
 else version (Solaris)
 {
     int sched_yield();
@@ -184,6 +211,12 @@ else version( FreeBSD )
     int sched_get_priority_max(int);
     int sched_rr_get_interval(pid_t, timespec*);
 }
+else version( NetBSD )
+{
+    int sched_get_priority_min(int);
+    int sched_get_priority_max(int);
+    int sched_rr_get_interval(pid_t, timespec*);
+}
 else version (Solaris)
 {
     int sched_get_priority_max(int);
