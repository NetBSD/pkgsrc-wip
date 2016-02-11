$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/resource.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/resource.d
@@ -234,6 +234,75 @@ else version (FreeBSD)
         RLIMIT_AS     = 10,
     }
 }
+else version( NetBSD )
+{
+    enum
+    {
+        PRIO_PROCESS,
+        PRIO_PGRP,
+        PRIO_USER,
+    }
+
+    alias ulong rlim_t;
+
+    enum
+    {
+        RLIM_INFINITY = rlim_t.max,
+        RLIM_SAVED_MAX = RLIM_INFINITY,
+        RLIM_SAVED_CUR = RLIM_INFINITY,
+    }
+
+    enum
+    {
+        RUSAGE_SELF,
+        RUSAGE_CHILDREN = -1,
+    }
+
+    struct rusage {
+        timeval ru_utime;	/* user time used */
+        timeval ru_stime;	/* system time used */
+ 	long	ru_maxrss;	/* max resident set size */
+        alias 	ru_ixrss ru_first;
+ 	long	ru_ixrss;	/* integral shared memory size */
+ 	long	ru_idrss;	/* integral unshared data " */
+ 	long	ru_isrss;	/* integral unshared stack " */
+ 	long	ru_minflt;	/* page reclaims */
+ 	long	ru_majflt;	/* page faults */
+ 	long	ru_nswap;	/* swaps */
+ 	long	ru_inblock;	/* block input operations */
+ 	long	ru_oublock;	/* block output operations */
+ 	long	ru_msgsnd;	/* messages sent */
+ 	long	ru_msgrcv;	/* messages received */
+ 	long	ru_nsignals;	/* signals received */
+ 	long	ru_nvcsw;	/* voluntary context switches */
+ 	long	ru_nivcsw;	/* involuntary " */
+        alias   ru_nivcsw ru_last;
+    };
+
+    enum
+    {
+        RLIMIT_CPU     = 0,		/* cpu time in milliseconds */
+	RLIMIT_FSIZE   = 1,		/* maximum file size */
+	RLIMIT_DATA    = 2,		/* data size */
+	RLIMIT_STACK   = 3,		/* stack size */
+	RLIMIT_CORE    = 4,		/* core file size */
+	RLIMIT_RSS     = 5,		/* resident set size */
+	RLIMIT_MEMLOCK = 6,		/* locked-in-memory address space */
+	RLIMIT_NPROC   = 7,		/* number of processes */
+	RLIMIT_NOFILE  = 8,		/* number of open files */
+	RLIMIT_SBSIZE  = 9,		/* maximum size of all socket buffers */
+	RLIMIT_AS      = 10,		/* virtual process size (inclusive of mmap) */
+	RLIMIT_VMEM    = RLIMIT_AS,	/* common alias */
+	RLIMIT_NTHR    = 11,		/* number of threads */
+	RLIM_NLIMITS   = 12,		/* number of resource limits */
+    }
+
+    int getpriority(int, id_t);
+    int getrlimit(int, rlimit*);
+    int getrusage(int, rusage*);
+    int setpriority(int, id_t, int);
+    int setrlimit(int, const rlimit*);
+}
 else version (Solaris)
 {
     enum
