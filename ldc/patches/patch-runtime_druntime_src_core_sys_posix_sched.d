$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sched.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sched.d
@@ -86,6 +86,17 @@ else version( FreeBSD )
     enum SCHED_OTHER    = 2;
     enum SCHED_RR       = 3;
 }
+else version( NetBSD )
+{
+    struct sched_param
+    {
+        int sched_priority;
+    }
+
+    enum SCHED_FIFO     = 1;
+    enum SCHED_OTHER    = 0;
+    enum SCHED_RR       = 2;
+}
 else version (Solaris)
 {
     struct sched_param
@@ -144,6 +155,10 @@ else version( FreeBSD )
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
@@ -184,6 +199,12 @@ else version( FreeBSD )
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
