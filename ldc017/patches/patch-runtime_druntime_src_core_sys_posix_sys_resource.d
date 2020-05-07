$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/resource.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/resource.d
@@ -292,6 +292,64 @@ else version (DragonFlyBSD)
         RLIMIT_AS     = 10,
     }
 }
+else version (NetBSD)
+{
+    enum
+    {
+        PRIO_PROCESS = 0,
+        PRIO_PGRP    = 1,
+        PRIO_USER    = 2,
+    }
+
+    alias long rlim_t;
+
+    enum
+    {
+        RLIM_INFINITY   = (cast(rlim_t)((cast(ulong) 1 << 63) - 1)),
+        // FreeBSD explicitly does not define the following:
+        //RLIM_SAVED_MAX,
+        //RLIM_SAVED_CUR,
+    }
+
+    enum
+    {
+        RUSAGE_SELF     =  0,
+        RUSAGE_CHILDREN = -1,
+    }
+
+    struct rusage
+    {
+        timeval ru_utime;
+        timeval ru_stime;
+        c_long ru_maxrss;
+        alias ru_ixrss ru_first;
+        c_long ru_ixrss;
+        c_long ru_idrss;
+        c_long ru_isrss;
+        c_long ru_minflt;
+        c_long ru_majflt;
+        c_long ru_nswap;
+        c_long ru_inblock;
+        c_long ru_oublock;
+        c_long ru_msgsnd;
+        c_long ru_msgrcv;
+        c_long ru_nsignals;
+        c_long ru_nvcsw;
+        c_long ru_nivcsw;
+        alias ru_nivcsw ru_last;
+    }
+
+    enum
+    {
+        RLIMIT_CORE   =  4,
+        RLIMIT_CPU    =  0,
+        RLIMIT_DATA   =  2,
+        RLIMIT_FSIZE  =  1,
+        RLIMIT_NOFILE =  8,
+        RLIMIT_STACK  =  3,
+        RLIMIT_AS     = 10,
+    }
+}
 else version (Solaris)
 {
     enum
@@ -473,6 +531,12 @@ else version (DragonFlyBSD)
 {
     int getrlimit(int, rlimit*);
     int getrusage(int, rusage*);
+    int setrlimit(int, in rlimit*);
+}
+else version (NetBSD)
+{
+    int getrlimit(int, rlimit*);
+    int getrusage(int, rusage*);
     int setrlimit(int, in rlimit*);
 }
 else version (Solaris)
