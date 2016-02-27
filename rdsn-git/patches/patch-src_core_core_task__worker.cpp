$NetBSD$

--- src/core/core/task_worker.cpp.orig	2016-02-27 19:59:48.000000000 +0000
+++ src/core/core/task_worker.cpp
@@ -51,6 +51,10 @@
 # include <mach/thread_policy.h>
 # endif
 
+# ifdef __NetBSD__
+# include <sched.h>
+# endif
+
 # endif
 
 
@@ -156,6 +160,8 @@ void task_worker::set_name(const char* n
     err = pthread_setname_np(tid, thread_name.c_str());
     # elif defined(__APPLE__)
     err = pthread_setname_np(thread_name.c_str());
+    # elif defined(__NetBSD__)
+    err = pthread_setname_np(tid, "%s", (void*)thread_name.c_str());
     # endif
     if (err != 0)
     {
@@ -255,10 +261,16 @@ void task_worker::set_affinity(uint64_t 
         THREAD_AFFINITY_POLICY_COUNT
         ));
 # else
-    # ifdef __FreeBSD__
+    # if defined(__FreeBSD__) || defined(__NetBSD__)
         # ifndef cpu_set_t
             # define cpu_set_t cpuset_t
         # endif
+        # ifndef CPU_ZERO
+            # define CPU_ZERO cpuset_zero
+        # endif
+        # ifndef CPU_SET
+            # define CPU_SET cpuset_set
+        # endif
     # endif
     cpu_set_t cpuset;
     int nr_bits = std::min(nr_cpu, static_cast<int>(sizeof(affinity) * 8));
