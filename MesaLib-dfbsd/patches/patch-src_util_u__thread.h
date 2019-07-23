$NetBSD: patch-src_util_u__thread.h,v 1.2 2019/01/20 09:50:28 tnn Exp $

handle NetBSD-style pthread_setaffinity_np(3)

From FreeBSD ports / DragonFly dports

- Implement setting thread name
- Use monotonic clock for timeouts

https://reviews.freebsd.org/D17872

--- src/util/u_thread.h.orig	2019-04-05 10:53:23.000000000 +0000
+++ src/util/u_thread.h
@@ -34,6 +34,13 @@
 
 #ifdef HAVE_PTHREAD
 #include <signal.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+# if !defined(__DragonFly__)
+#  define cpu_set_t cpuset_t
+# endif
+#undef ALIGN /* Avoid conflict on FreeBSD in main/macros.h */
+#endif
 #endif
 
 static inline thrd_t u_thread_create(int (*routine)(void *), void *param)
@@ -64,6 +71,10 @@ static inline void u_thread_setname( con
       (__GLIBC__ >= 3 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 12)) && \
       defined(__linux__)
    pthread_setname_np(pthread_self(), name);
+#  elif defined(__DragonFly__) || defined(__FreeBSD__)
+   pthread_set_name_np(pthread_self(), name);
+#  elif defined(__NetBSD__)
+   pthread_setname_np(pthread_self(), "%s", (void*)name);
 #  endif
 #endif
    (void)name;
@@ -83,6 +94,17 @@ static inline void
 util_pin_thread_to_L3(thrd_t thread, unsigned L3_index, unsigned cores_per_L3)
 {
 #if defined(HAVE_PTHREAD_SETAFFINITY)
+#if defined(__NetBSD__) && defined(SETAFFINITY_NP_NETBSD)
+   cpuset_t *cpuset;
+   cpuset = cpuset_create();
+   if (cpuset == NULL)
+      return;
+   cpuset_zero(cpuset);
+   for (unsigned i = 0; i < cores_per_L3; i++)
+      cpuset_set(L3_index * cores_per_L3 + i, cpuset);
+   pthread_setaffinity_np(thread, cpuset_size(cpuset), cpuset);
+   cpuset_destroy(cpuset);
+#else
    cpu_set_t cpuset;
 
    CPU_ZERO(&cpuset);
@@ -90,6 +112,7 @@ util_pin_thread_to_L3(thrd_t thread, uns
       CPU_SET(L3_index * cores_per_L3 + i, &cpuset);
    pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
 #endif
+#endif
 }
 
 /**
@@ -103,6 +126,35 @@ static inline int
 util_get_L3_for_pinned_thread(thrd_t thread, unsigned cores_per_L3)
 {
 #if defined(HAVE_PTHREAD_SETAFFINITY)
+#if defined(__NetBSD__) && defined(SETAFFINITY_NP_NETBSD)
+   cpuset_t *cpuset;
+
+   cpuset = cpuset_create();
+   if (cpuset == NULL)
+      return -1;
+
+   if (pthread_getaffinity_np(thread, cpuset_size(cpuset), cpuset) == 0) {
+      int L3_index = -1;
+
+      for (unsigned i = 0; i < cpuset_size(cpuset); i++) {
+         if (cpuset_isset(i, cpuset)) {
+            int x = i / cores_per_L3;
+
+            if (L3_index != x) {
+               if (L3_index == -1)
+                  L3_index = x;
+               else {
+                  cpuset_destroy(cpuset);
+                  return -1; /* multiple L3s are set */
+               }
+            }
+         }
+      }
+      cpuset_destroy(cpuset);
+      return L3_index;
+   }
+   cpuset_destroy(cpuset);
+#else
    cpu_set_t cpuset;
 
    if (pthread_getaffinity_np(thread, sizeof(cpuset), &cpuset) == 0) {
@@ -123,6 +175,7 @@ util_get_L3_for_pinned_thread(thrd_t thr
       return L3_index;
    }
 #endif
+#endif
    return -1;
 }
 
@@ -134,7 +187,7 @@ util_get_L3_for_pinned_thread(thrd_t thr
 static inline int64_t
 u_thread_get_time_nano(thrd_t thread)
 {
-#if defined(__linux__) && defined(HAVE_PTHREAD)
+#if (defined(__linux__) || defined(USE_PTHREAD_GETCPUCLOCKID)) && defined(HAVE_PTHREAD)
    struct timespec ts;
    clockid_t cid;
 
