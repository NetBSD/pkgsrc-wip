$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sched.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sched.d
@@ -97,6 +97,17 @@ else version( DragonFlyBSD )
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
@@ -159,6 +170,10 @@ else version( DragonFlyBSD )
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
@@ -203,6 +218,12 @@ else version( DragonFlyBSD )
 {
     int sched_get_priority_min(int);
     int sched_get_priority_max(int);
+    int sched_rr_get_interval(pid_t, timespec*);
+}
+else version( NetBSD )
+{
+    int sched_get_priority_min(int);
+    int sched_get_priority_max(int);
     int sched_rr_get_interval(pid_t, timespec*);
 }
 else version (Solaris)
