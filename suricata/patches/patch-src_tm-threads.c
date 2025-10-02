$NetBSD$

--- src/tm-threads.c.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/tm-threads.c
@@ -65,14 +65,16 @@ thread_local uint64_t rwr_lock_wait_tick
 thread_local uint64_t rwr_lock_cnt;
 #endif
 
-#ifdef OS_FREEBSD
+#if defined OS_FREEBSD
 #include <sched.h>
 #include <sys/param.h>
 #include <sys/resource.h>
 #include <sys/cpuset.h>
 #include <sys/thr.h>
 #define cpu_set_t cpuset_t
-#endif /* OS_FREEBSD */
+#elif defined __NetBSD__
+#include <err.h>
+#endif /* OS_FREEBSD __NetBSD__ */
 
 /* prototypes */
 static int SetCPUAffinity(uint16_t cpu);
@@ -705,6 +707,8 @@ static int SetCPUAffinitySet(cpu_set_t *
 #if defined OS_FREEBSD
     int r = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID,
                                SCGetThreadIdLong(), sizeof(cpu_set_t),cs);
+#elif defined __NetBSD__
+    int r = pthread_setaffinity_np(SCGetThreadIdLong(), cpuset_size(*cs), *cs);
 #elif OS_DARWIN
     int r = thread_policy_set(mach_thread_self(), THREAD_AFFINITY_POLICY,
                               (void*)cs, THREAD_AFFINITY_POLICY_COUNT);
@@ -751,7 +755,25 @@ static int SetCPUAffinity(uint16_t cpuid
                SCGetThreadIdLong(), cpu);
 
     return 0;
+#elif defined __NetBSD__
+    cpuset_t *cset = cpuset_create();
+    if (cset == NULL) {
+      SCLogError("Error creating cpu set " "cpu %d", cpu);
+      //      warnc(EXIT_FAILURE, "cpuset_create");
+      return -1;
+    }
+    cpuset_set((cpuid_t)cpu, cset);
+
+    int r = SetCPUAffinitySet(&cset);
+    if (r) {
+      SCLogError("Error setting affinity for "
+		 "cpu %d: %s",
+		 cpu, strerror(r));
+      //      warnc(EXIT_FAILURE, "pthread_setaffinity_np failed: %d, %s", r, strerror(r));
+    }
+    cpuset_destroy(cset);
 
+    return r;
 #else
     cpu_set_t cs;
     memset(&cs, 0, sizeof(cs));
